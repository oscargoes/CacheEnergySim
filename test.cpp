#include <algorithm>
#include <bit>
#include <cassert>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <ranges>
#include <span>
#include <string>
#include <tuple>
#include <vector>
#include <cstdlib> 
#include <cmath>

// Our cache simulator
class CacheSim
{
public:
  // Constructor
  CacheSim(std::string input, unsigned bs, unsigned a, unsigned c, unsigned mp,
           unsigned wbp, int ct)
  {
    // Initialize the input file stream object
    infile.open(input);

    // Set all of our cache settings
    block_size = bs;
    associativity = a;
    capacity = c;
    miss_penalty = mp;
    dirty_wb_penalty = wbp;
    cache_type = ct;

    // Calculate the number of blocks
    // Assume this divides evenly
    auto num_blocks = capacity / block_size;

    // Create our cache based on the number of blocks
    tags.resize(num_blocks);
    dirty.resize(num_blocks);
    valid.resize(num_blocks);
    priority.resize(num_blocks);
    og_address.resize(num_blocks);

    // Calculate values for traversal
    // Cache lines come in the following format:
    // |****** TAG ******|**** SET ****|** OFFSET **|
    // Calculate the number of offset bits
    auto block_bits = std::popcount(block_size - 1);

    // Calculate the number of set bits, and create a mask of 1s
    set_offset = block_bits;
    auto sets = capacity / (block_size * associativity);
    set_mask = sets - 1;
    auto set_bits = std::popcount(set_mask);

    // Calculate the bit-offset for the tag and create a mask of 1s
    // Always use 64-bit addresses
    tag_offset = block_bits + set_bits;
  }

  // Probe the cache
  std::tuple<bool, bool, std::uint64_t> probe(int type, std::uint64_t address)
  { // int type was bool CHANGED

    bool type2 = false;

    if (type == 1)
    {
      type2 = true;
    }

    // Calculate the set from the address
    auto set = get_set(address);
    auto tag = get_tag(address);

    // create a spans for our set
    auto base = set * associativity;
    std::span local_tags{tags.data() + base, associativity};
    std::span local_dirty{dirty.data() + base, associativity};
    std::span local_valid{valid.data() + base, associativity};
    std::span local_priority{priority.data() + base, associativity};
    std::span og_address{priority.data() + base, associativity};

    // Check each cache line in the set
    auto hit = false;
    int invalid_index = -1;
    int index;
    for (auto i = 0u; i < local_valid.size(); i++) {
      // Check if the block is invalid
      if (!local_valid[i]) {
        // Keep track of invalid entries in case we need them
        invalid_index = i;
        continue;
      }

      // Check if the tag matches
      if (tag != local_tags[i]) continue;

      // We found the line, so mark it as a hit
      hit = true;
      index = i;
      og_address[index] = address;

      // Update dirty flag
      local_dirty[index] |= type2;

      // Break out of the loop
      break;
    }

    // Find an element to replace if it wasn't a hit
    auto dirty_wb = false;
    std::uint64_t evicted_address;
    if (!hit) {
      if (cache_type == 1) {
        // L1 cache is direct mapped, use only available index (should be 0 in this case)
        index = local_valid.size() - 1;

        // make valid if not already
        local_valid[index] = 1;

        // check if dirty writeback happens. Shouldnt matter since we do write-through?
        dirty_wb = local_dirty[index];
        if (dirty_wb) {
          evicted_address = og_address[index];
        }

        // Update the tag and dirty state
        local_tags[index] = tag;
        local_dirty[index] = type2;
        og_address[index] = address;
      }

      if (cache_type == 2) {
        // First try and use an invalid line (if available)
        if (invalid_index >= 0) {
          index = invalid_index;
        } else {  // if no lines invalid, then randomly pick line in set to replace
          index = rand() % associativity;
        }
        dirty_wb = local_dirty[index];  // if true then write back to memory.
        if (dirty_wb) {
          evicted_address = og_address[index];
        }
        local_valid[index] = 1;
        local_tags[index] = tag;
        local_dirty[index] = type2;
        og_address[index] = address;
        //   // Otherwise, evict the lowest-priority cache block (largest value)
        //   else {
        //     auto max_element = std::ranges::max_element(local_priority);
        //     index = std::distance(begin(local_priority), max_element);
        //     dirty_wb = local_dirty[index];
        //   }

        //   // Update the tag and dirty state
        //   local_tags[index] = tag;
        //   local_dirty[index] = type2;
        // }

        // // Update the priority
        // // Go through each element
        // // Increase the priority of all the blocks with a lower priority than the
        // // one we are accessing
        // // High priority -> Low priority = 0 -> associativity - 1
        // std::transform(local_priority.begin(), end(local_priority),
        //               begin(local_priority), [&](int p)
        //               {
        //                 if (p <= local_priority[index] && p < associativity)
        //                   return p + 1;
        //                 else
        //                   return p; });

        // // Currently accessed block has the highest priority (0)
        // priority[index] = 0;

      }

    }
    
    return {hit, dirty_wb, evicted_address};
  }

  void evict(std::uint64_t address) {   // should only be called on l1 cache
    // Calculate the set from the address
    auto set = get_set(address);
    auto tag = get_tag(address);

    // create a spans for our set
    auto base = set * associativity;
    std::span local_tags{tags.data() + base, associativity};
    std::span local_dirty{dirty.data() + base, associativity};
    std::span local_valid{valid.data() + base, associativity};
    std::span local_priority{priority.data() + base, associativity};
    std::span og_address{priority.data() + base, associativity};

    if (local_valid[0] && tag == local_tags[0]) {
      local_valid[0] = 0;
    }

  }

  // Update the stats
  void update_stats(int instructions, bool type, bool hit, bool dirty_wb)
  {
    mem_accesses_++;
    writes_ += type;
    misses_ += !hit;
    // instructions_ += instructions;
    dirty_wb_ += dirty_wb;
  }

  void update_timing_energy(double time, bool active, std::uint64_t penalty) {
    if (active) {
      active_time += time;
    } else {
      idle_time += time;
    }

    penalty_energy += penalty;
  }

  // void dump_stats()
  // {
  //   // Print the cache settings
  //   std::cout << "CACHE SETTINGS\n";
  //   std::cout << "       Cache Size (Bytes): " << capacity << '\n';
  //   std::cout << "           Associativity : " << associativity << '\n';
  //   std::cout << "       Block Size (Bytes): " << block_size << '\n';
  //   std::cout << "    Miss Penalty (Cycles): " << miss_penalty << '\n';
  //   std::cout << "Dirty WB Penalty (Cycles): " << dirty_wb_penalty << '\n';
  //   std::cout << '\n';

  //   // Print the access breakdown
  //   std::cout << "CACHE ACCESS STATS\n";
  //   std::cout << "TOTAL ACCESSES: " << mem_accesses_ << '\n';
  //   std::cout << "         READS: " << mem_accesses_ - writes_ << '\n';
  //   std::cout << "        WRITES: " << writes_ << '\n';
  //   std::cout << '\n';

  //   // Print the miss-rate breakdown
  //   std::cout << "CACHE MISS-RATE STATS\n";
  //   double miss_rate = (double)misses_ / (double)mem_accesses_ * 100.0;
  //   auto hits = mem_accesses_ - misses_;
  //   std::cout << "     MISS-RATE: " << miss_rate << '\n';
  //   std::cout << "        MISSES: " << misses_ << '\n';
  //   std::cout << "          HITS: " << hits << '\n';
  //   std::cout << '\n';

  //   // Print the instruction breakdown
  //   std::cout << "CACHE IPC STATS\n";
  //   auto cycles = miss_penalty * misses_;
  //   cycles += dirty_wb_penalty * dirty_wb_;
  //   // cycles += instructions_;
  //   double ipc = (double)instructions_ / (double)cycles;
  //   std::cout << "           IPC: " << ipc << '\n';
  //   // std::cout << "  INSTRUCTIONS: " << instructions_ << '\n';
  //   std::cout << "        CYCLES: " << cycles << '\n';
  //   std::cout << "      DIRTY WB: " << dirty_wb_ << '\n';

  //   // Print timing stuffs
  //   std::cout << "CACHE TIMING DATA\n";
  //   std::cout << "           Idle: " << idle_time << '\n';
  //   std::cout << "           Active: " << active_time << '\n';
  //   std::cout << "         Energy pen: " << penalty_energy << '\n';
  // }

  std::int64_t getMisses() {
    return misses_;
  }
  std::int64_t getHits() {
    return mem_accesses_ - misses_;
  }
  double getIdle() {
    return idle_time;
  }
  double getActive() {
    return active_time;
  }
  unsigned long getPenalty() {
    return penalty_energy;
  }

  // Destructor
  ~CacheSim()
  {
    // infile.close();
    //dump_stats();
  }

private:
  // Input trace file
  std::ifstream infile;

  int cache_type = 0;

  // Cache settings
  unsigned block_size;
  unsigned associativity;
  unsigned capacity;
  unsigned miss_penalty;
  unsigned dirty_wb_penalty;

  // Access settings
  unsigned set_offset;
  unsigned tag_offset;
  unsigned set_mask;

  // The actual cache state
  std::vector<std::uint64_t> tags;
  std::vector<char> dirty;
  std::vector<char> valid;
  std::vector<int> priority;
  std::vector<std::uint64_t> og_address;

  // Cache statistics
  std::int64_t writes_ = 0;
  std::int64_t mem_accesses_ = 0;
  std::int64_t misses_ = 0;
  std::int64_t dirty_wb_ = 0;
  std::int64_t instructions_ = 0;

  // Timing statistics
  double active_time = 0;
  double idle_time = 0;
  unsigned long penalty_energy = 0;

  // Extract the set number
  // Shift the set to the bottom then extract the set bits
  int get_set(std::uint64_t address)
  {
    auto shifted_address = address >> set_offset;
    return shifted_address & set_mask;
  }

  // Extract the tag
  // Shift the tag to the bottom
  // No need to use mask (tag is all upper remaining bits)
  std::uint64_t get_tag(std::uint64_t address)
  {
    return address >> tag_offset;
  }
};

// Get memory access from the trace file
std::tuple<int, std::uint64_t, std::uint64_t> parse_line(std::string access)
{
  // What we want to parse
  int type;
  std::uint64_t address;
  std::uint64_t instructions; // used to be int type CHANGED

  // Parse from the string we read from the file
  sscanf(access.c_str(), "%d %lx %lx", &type, &address, &instructions); // second lx used to be d CHANGED

  return {type, address, instructions};
}

double average(std::vector<unsigned long>& vec) {
  double sum = 0;
  for (unsigned long value : vec) {
    sum += (double)value / 10;
  }
  return sum;
}

int main()
{
  std::string filenames[] = {"dinfiles/008.espresso.din", 
                            "dinfiles/013.spice2g6.din", 
                            "dinfiles/015.doduc.din", 
                            "dinfiles/022.li.din",
                            "dinfiles/023.eqntott.din",
                            "dinfiles/026.compress.din",
                            "dinfiles/034.mdljdp2.din",
                            "dinfiles/039.wave5.din",
                            "dinfiles/047.tomcatv.din",
                            "dinfiles/048.ora.din",
                            "dinfiles/085.gcc.din",
                            "dinfiles/089.su2cor.din",
                            "dinfiles/090.hydro2d.din",
                            "dinfiles/093.nasa7.din",
                            "dinfiles/094.fpppp.din"};
  // Kill the program if we didn't get an input file
  //assert(argc == 2);

  for (int i = 0; i < 15; ++i) {
    std::cout << "RUNNING CACHE SIM ON " << filenames[i] << "\n";
    unsigned associativity[] = {2, 4, 8};
    for (int a = 0; a < 3; ++a) {

      std::vector<unsigned long> L1i_total_access;
      std::vector<unsigned long> L1ihits;
      std::vector<unsigned long> L1imisses;
      std::vector<unsigned long> L1d_total_access;
      std::vector<unsigned long> L1dhits;
      std::vector<unsigned long> L1dmisses;
      std::vector<unsigned long> L2_total_access;
      std::vector<unsigned long> L2hits;
      std::vector<unsigned long> L2misses;
      std::vector<unsigned long> L1ienergy;
      std::vector<unsigned long> L1denergy;
      std::vector<unsigned long> L2energy;
      std::vector<unsigned long> DRAMenergy;
      std::vector<unsigned long> total_runtime;
      std::vector<unsigned long> mem_active;
      std::vector<unsigned long> total_energy;

      for (int j = 0; j < 10; ++j) {
        // File location
        std::string location(filenames[i]);


        // Hard coded cache settings
        unsigned block_sizeL1i = 1 << 6;
        unsigned associativityL1i = 1 << 0;
        unsigned capacityL1i = 1 << 15;
        unsigned miss_penaltyL1i = 30;
        unsigned dirty_wb_penaltyL1i = 2;

        // Hard coded cache settings
        unsigned block_sizeL1d = 1 << 6;
        unsigned associativityL1d = 1 << 0;
        unsigned capacityL1d = 1 << 15;
        unsigned miss_penaltyL1d = 30;
        unsigned dirty_wb_penaltyL1d = 2;

        // Hard coded cache settings
        unsigned block_sizeL2 = 1 << 6;
        unsigned associativityL2 = associativity[a]; // change to test effect of diff associativity
        unsigned capacityL2 = 1 << 18;
        unsigned miss_penaltyL2 = 30;
        unsigned dirty_wb_penaltyL2 = 2;

        // Create our simulator
        // CacheSim simulator(location, block_size, associativity, capacity,
        // miss_penalty, dirty_wb_penalty);

        CacheSim L1i(location, block_sizeL1i, associativityL1i, capacityL1i, miss_penaltyL1i, dirty_wb_penaltyL1i, 1);

        CacheSim L1d(location, block_sizeL1d, associativityL1d, capacityL1d, miss_penaltyL1d, dirty_wb_penaltyL1d, 1);

        CacheSim L2(location, block_sizeL2, associativityL2, capacityL2, miss_penaltyL2, dirty_wb_penaltyL2, 2);


        // Timing statistics
        double r_active_time = 0;
        double r_idle_time = 0;
        uint64_t r_penalty_energy = 0;


        // parse trace and probe caches
        std::ifstream infile;
        infile.open(location);
        std::string line;
        while (std::getline(infile, line))
        {
          // Get the data for the access
          auto [type, address, instructions] = parse_line(line);

          r_idle_time += 0.5;
          L1i.update_timing_energy(0.5, false, 0u);
          L1d.update_timing_energy(0.5, false, 0u);
          L2.update_timing_energy(0.5, false, 0u);

          // Probe the cache, if miss, probe next cache
          bool l1Hit;
          if (type == 0)
          {
            auto [hitL1d, dirty_wbL1d, evicted] = L1d.probe(type, address);
            l1Hit = hitL1d;
            L1d.update_stats(instructions, type, hitL1d, dirty_wbL1d);

            r_idle_time += 0.5;
            L1i.update_timing_energy(0.5, false, 0u);
            L1d.update_timing_energy(0.5, true, 0u);
            L2.update_timing_energy(0.5, false, 0u);
          }
          else if (type == 1)
          {
            auto [hitL1d, dirty_wbL1d, evicted] = L1d.probe(type, address);
            l1Hit = hitL1d;
            L1d.update_stats(instructions, type, hitL1d, dirty_wbL1d);

            r_idle_time += 0.5;
            L1i.update_timing_energy(0.5, false, 0u);
            L1d.update_timing_energy(0.5, true, 0u);
            L2.update_timing_energy(0.5, false, 0u);
          }
          else if (type == 2)
          {
            auto [hitL1i, dirty_wbL1i, evicted] = L1i.probe(type, address);
            l1Hit = hitL1i;
            type = 0;
            L1i.update_stats(instructions, type, hitL1i, dirty_wbL1i);
            type = 2;

            r_idle_time += 0.5;
            L1i.update_timing_energy(0.5, true, 0u);
            L1d.update_timing_energy(0.5, false, 0u);
            L2.update_timing_energy(0.5, false, 0u);
          }
          else if (type == 3)
          {
          }
          else
          {
            // do nothing
          }

          if (!l1Hit)
          {
            auto [hitL2, dirty_wbL2, evicted] = L2.probe(type, address);
            if (type == 2)
            {
              type = 0; // instruction fetch is a read not write
              L2.update_stats(instructions, type, hitL2, dirty_wbL2);
              type = 2;
            }
            else {
              L2.update_stats(instructions, type, hitL2, dirty_wbL2);
            }
            
            r_idle_time += 4.5;
            L1i.update_timing_energy(4.5, false, 0u);
            L1d.update_timing_energy(4.5, false, 0u);
            L2.update_timing_energy(4.5, true, 5);


            if (!hitL2)
            {
              // DRAM Access, use L2 miss cost
              r_active_time += 45;
              r_penalty_energy += 640;
              L1i.update_timing_energy(45, false, 0u);
              L1d.update_timing_energy(45, false, 0u);
              L2.update_timing_energy(45, false, 0u);
            }
            else {
              if (dirty_wbL2) {
                // dirty write back, had to evict line and write to memory
                r_active_time += 45;
                r_penalty_energy += 640;
                L1i.update_timing_energy(45, false, 0u);
                L1d.update_timing_energy(45, false, 0u);
                L2.update_timing_energy(45, false, 0u);
                // Evicted line in L2 so evict in L1 as well since change has already been written back to ram
                if (type == 2) {
                  L1i.evict(evicted);
                  r_idle_time += 0.5;
                  L1i.update_timing_energy(0.5, true, 0u);
                  L1d.update_timing_energy(0.5, false, 0u);
                  L2.update_timing_energy(0.5, false, 0u);
                } else {
                  L1d.evict(evicted);
                  r_idle_time += 0.5;
                  L1i.update_timing_energy(0.5, false, 0u);
                  L1d.update_timing_energy(0.5, true, 0u);
                  L2.update_timing_energy(0.5, false, 0u);
                }
              }
            }
          }
        }
        // simulator.run();
        // L1i.dump_stats();
        // L1d.dump_stats();
        // L2.dump_stats();

            // Print timing stuffs
          // std::cout << "DRAM TIMING DATA\n";
          // std::cout << "           Idle: " << r_idle_time << '\n';
          // std::cout << "           Active: " << r_active_time << '\n';
          // std::cout << "         Energy pen: " << r_penalty_energy << '\n';
          // std::cout << "           Total Time: " << r_idle_time + r_active_time << " nanoseconds\n";
          // std::cout << "         Total Energy: " << r_penalty_energy +(r_idle_time * .8 * 1000 ) + (r_active_time * 4 * 1000)<< " picojoules\n\n\n\n\n";

          L1i_total_access.push_back(L1i.getHits() + L1i.getMisses());
          L1ihits.push_back(L1i.getHits());
          L1imisses.push_back(L1i.getMisses());
          L1d_total_access.push_back(L1d.getHits() + L1d.getMisses());
          L1dhits.push_back(L1d.getHits());
          L1dmisses.push_back(L1d.getMisses());
          L2_total_access.push_back(L2.getHits() + L2.getMisses());
          L2hits.push_back(L2.getHits());
          L2misses.push_back(L2.getMisses());
          L1ienergy.push_back((L1i.getIdle() * .5 * 1000 ) + (L1i.getActive() * 1 * 1000 ));
          L1denergy.push_back((L1d.getIdle() * .5 * 1000 ) + (L1d.getActive() * 1 * 1000 ));
          L2energy.push_back((L2.getIdle() * .8 * 1000 ) + (L1i.getActive() * 2 * 1000 ) + L2.getPenalty());
          DRAMenergy.push_back(r_penalty_energy + (r_idle_time * .8 * 1000 ) + (r_active_time * 4 * 1000));
          total_runtime.push_back(L2.getIdle() + L2.getActive()); // should be the same for all components
          mem_active.push_back(L1i.getActive() + L1d.getActive() + L2.getActive() + r_active_time);
          total_energy.push_back(L1ienergy[j] + L1denergy[j] + L2energy[j] + DRAMenergy[j]);

          infile.close();
      }

      // OUTPUT Results

      std::cout << "RESULTS FOR " << filenames[i] << " WITH L2 CACHE SET ASSOCIATIVITY = " << associativity[a] <<"\n";
      std::cout << "AVG L1-icache Accesses: " << average(L1i_total_access) << "   AVG L1-icache Hits: " << average(L1ihits) << "    AVG L1-icache Misses: " << average(L1imisses) << '\n';
      std::cout << "AVG L1-dcache Accesses: " << average(L1d_total_access) << "   AVG L1-dcache Hits: " << average(L1dhits) << "    AVG L1-dcache Misses: " << average(L1dmisses) << '\n';
      std::cout << "AVG L2 Accesses: " << average(L2_total_access) << "   AVG L2 Hits: " << average(L2hits) << "    AVG L2 Misses: " << average(L2misses) << '\n';
      std::cout << "AVG L1-icache Static + Dynamic Energy:     " << average(L1ienergy) << " picojoules" << '\n';
      std::cout << "AVG L1-dcache Static + Dynamic Energy:     " << average(L1denergy) << " picojoules" << '\n';
      std::cout << "AVG L2 Static + Dynamic Energy:     " << average(L2energy) << " picojoules" << '\n';
      std::cout << "AVG DRAM Static + Dynamic Energy:   " << average(DRAMenergy) << " picojoules" << '\n';
      std::cout << "Mean Total Runtime:                 " << average(total_runtime) << " nanoseconds" << '\n';
      std::cout << "Mean Time L1 + L2 + DRAM Active (Total access time):    " << average(mem_active) << " nanoseconds" << '\n';
      std::cout << "Mean Total Energy:                  " << average(total_energy) << " picojoules" << "\n\n\n";
    }
    std::cout << "========================================================================================================\n";
  }
  return 0;
}