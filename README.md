# CacheEnergySim

***YOU MUST HAVE g++ or gcc version 10 or above for the code to work/compile.***

To run the program, first try the run.sh file. This will attempt to compile test.cpp
using g++ and then run the generated executable.

If this does not work, try manually compiling the test.cpp file using the commands in
the run.sh file. 
> It could also be possible that the permissions need to be updated using:
> chmod -x run.sh

If that also does not work, run2.sh attempts to compile the c++ file using the correct
version of clang. It then tries to run the executable generated. If this also doesn't
work, again, try manually running the commands in run2.sh.
> It could also be possible that the permissions need to be updated using:
> chmod -x run2.sh

There is nothing special for running our code. We simply have c++ file, however,
the libraries used in the file require at least g++ or gcc or some equivalent with a version
that is 10.1 or higher, which would be the most likely reason that an issue occurs.

In the worst case scenario that the file cannot be executed, we have provided the outtput
generated when we ran the program on our local machines below. 


RUNNING CACHE SIM ON dinfiles/008.espresso.din
RESULTS FOR dinfiles/008.espresso.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 809368   AVG L1-icache Hits: 807667    AVG L1-icache Misses: 1701
AVG L1-dcache Accesses: 190632   AVG L1-dcache Hits: 189630    AVG L1-dcache Misses: 1002
AVG L2 Accesses: 2703   AVG L2 Hits: 1902.9    AVG L2 Misses: 800.1
AVG L1-icache Static + Dynamic Energy:     7.26426e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.71742e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.63819e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.54261e+08 picojoules
Mean Total Runtime:                 1.04817e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    548168 nanoseconds
Mean Total Energy:                  3.89061e+09 picojoules


RESULTS FOR dinfiles/008.espresso.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 809368   AVG L1-icache Hits: 807667    AVG L1-icache Misses: 1701
AVG L1-dcache Accesses: 190632   AVG L1-dcache Hits: 189630    AVG L1-dcache Misses: 1002
AVG L2 Accesses: 2703   AVG L2 Hits: 1905    AVG L2 Misses: 798
AVG L1-icache Static + Dynamic Energy:     7.26379e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.71695e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.63811e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.53882e+08 picojoules
Mean Total Runtime:                 1.04807e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    548073 nanoseconds
Mean Total Energy:                  3.89006e+09 picojoules


RESULTS FOR dinfiles/008.espresso.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 809368   AVG L1-icache Hits: 807667    AVG L1-icache Misses: 1701
AVG L1-dcache Accesses: 190632   AVG L1-dcache Hits: 189630    AVG L1-dcache Misses: 1002
AVG L2 Accesses: 2703   AVG L2 Hits: 1905    AVG L2 Misses: 798
AVG L1-icache Static + Dynamic Energy:     7.26379e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.71695e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.63811e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.53882e+08 picojoules
Mean Total Runtime:                 1.04807e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    548073 nanoseconds
Mean Total Energy:                  3.89006e+09 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/013.spice2g6.din
RESULTS FOR dinfiles/013.spice2g6.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 784179   AVG L1-icache Hits: 781572    AVG L1-icache Misses: 2607
AVG L1-dcache Accesses: 215823   AVG L1-dcache Hits: 215030    AVG L1-dcache Misses: 793
AVG L2 Accesses: 3400   AVG L2 Hits: 2424    AVG L2 Misses: 976
AVG L1-icache Static + Dynamic Energy:     7.25656e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.83567e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.61933e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.88546e+08 picojoules
Mean Total Runtime:                 1.05922e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    559221 nanoseconds
Mean Total Energy:                  3.9171e+09 picojoules


RESULTS FOR dinfiles/013.spice2g6.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 784179   AVG L1-icache Hits: 781572    AVG L1-icache Misses: 2607
AVG L1-dcache Accesses: 215823   AVG L1-dcache Hits: 215030    AVG L1-dcache Misses: 793
AVG L2 Accesses: 3400   AVG L2 Hits: 2424    AVG L2 Misses: 976
AVG L1-icache Static + Dynamic Energy:     7.25656e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.83567e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.61933e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.88546e+08 picojoules
Mean Total Runtime:                 1.05922e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    559221 nanoseconds
Mean Total Energy:                  3.9171e+09 picojoules


RESULTS FOR dinfiles/013.spice2g6.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 784179   AVG L1-icache Hits: 781572    AVG L1-icache Misses: 2607
AVG L1-dcache Accesses: 215823   AVG L1-dcache Hits: 215030    AVG L1-dcache Misses: 793
AVG L2 Accesses: 3400   AVG L2 Hits: 2424    AVG L2 Misses: 976
AVG L1-icache Static + Dynamic Energy:     7.25656e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.83567e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.61933e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.88546e+08 picojoules
Mean Total Runtime:                 1.05922e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    559221 nanoseconds
Mean Total Energy:                  3.9171e+09 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/015.doduc.din
RESULTS FOR dinfiles/015.doduc.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 755193   AVG L1-icache Hits: 750974    AVG L1-icache Misses: 4219
AVG L1-dcache Accesses: 244807   AVG L1-dcache Hits: 241991    AVG L1-dcache Misses: 2816
AVG L2 Accesses: 7035   AVG L2 Hits: 4437.9    AVG L2 Misses: 2597.1
AVG L1-icache Static + Dynamic Energy:     7.63062e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.35465e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.64872e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.29447e+09 picojoules
Mean Total Runtime:                 1.14853e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    648526 nanoseconds
Mean Total Energy:                  4.67496e+07 picojoules


RESULTS FOR dinfiles/015.doduc.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 755193   AVG L1-icache Hits: 750974    AVG L1-icache Misses: 4219
AVG L1-dcache Accesses: 244807   AVG L1-dcache Hits: 241991    AVG L1-dcache Misses: 2816
AVG L2 Accesses: 7035   AVG L2 Hits: 4446.7    AVG L2 Misses: 2588.3
AVG L1-icache Static + Dynamic Energy:     7.62864e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.35267e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.64841e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.29288e+09 picojoules
Mean Total Runtime:                 1.14813e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    648130 nanoseconds
Mean Total Energy:                  4.44472e+07 picojoules


RESULTS FOR dinfiles/015.doduc.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 755193   AVG L1-icache Hits: 750974    AVG L1-icache Misses: 4219
AVG L1-dcache Accesses: 244807   AVG L1-dcache Hits: 241991    AVG L1-dcache Misses: 2816
AVG L2 Accesses: 7035   AVG L2 Hits: 4457    AVG L2 Misses: 2578
AVG L1-icache Static + Dynamic Energy:     7.62632e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.35036e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.64804e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.29102e+09 picojoules
Mean Total Runtime:                 1.14767e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    647667 nanoseconds
Mean Total Energy:                  4.17523e+07 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/022.li.din
RESULTS FOR dinfiles/022.li.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 742254   AVG L1-icache Hits: 739872    AVG L1-icache Misses: 2382
AVG L1-dcache Accesses: 257749   AVG L1-dcache Hits: 252922    AVG L1-dcache Misses: 4827
AVG L2 Accesses: 7209   AVG L2 Hits: 5841.9    AVG L2 Misses: 1367.1
AVG L1-icache Static + Dynamic Energy:     7.32545e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.11419e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.59151e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.07291e+09 picojoules
Mean Total Runtime:                 1.09396e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    593962 nanoseconds
Mean Total Energy:                  4.00838e+09 picojoules


RESULTS FOR dinfiles/022.li.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 742254   AVG L1-icache Hits: 739872    AVG L1-icache Misses: 2382
AVG L1-dcache Accesses: 257749   AVG L1-dcache Hits: 252922    AVG L1-dcache Misses: 4827
AVG L2 Accesses: 7209   AVG L2 Hits: 5889    AVG L2 Misses: 1320
AVG L1-icache Static + Dynamic Energy:     7.31485e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.10359e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.58981e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.0644e+09 picojoules
Mean Total Runtime:                 1.09184e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    591842 nanoseconds
Mean Total Energy:                  3.99606e+09 picojoules


RESULTS FOR dinfiles/022.li.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 742254   AVG L1-icache Hits: 739872    AVG L1-icache Misses: 2382
AVG L1-dcache Accesses: 257749   AVG L1-dcache Hits: 252922    AVG L1-dcache Misses: 4827
AVG L2 Accesses: 7209   AVG L2 Hits: 5889    AVG L2 Misses: 1320
AVG L1-icache Static + Dynamic Energy:     7.31485e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.10359e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.58981e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.0644e+09 picojoules
Mean Total Runtime:                 1.09184e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    591842 nanoseconds
Mean Total Energy:                  3.99606e+09 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/023.eqntott.din
RESULTS FOR dinfiles/023.eqntott.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 769759   AVG L1-icache Hits: 769542    AVG L1-icache Misses: 217
AVG L1-dcache Accesses: 230241   AVG L1-dcache Hits: 228185    AVG L1-dcache Misses: 2056
AVG L2 Accesses: 2273   AVG L2 Hits: 678    AVG L2 Misses: 1595
AVG L1-icache Static + Dynamic Energy:     7.33442e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.98562e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.62719e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.0963e+09 picojoules
Mean Total Runtime:                 1.082e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    582003 nanoseconds
Mean Total Energy:                  4.0555e+09 picojoules


RESULTS FOR dinfiles/023.eqntott.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 769759   AVG L1-icache Hits: 769542    AVG L1-icache Misses: 217
AVG L1-dcache Accesses: 230241   AVG L1-dcache Hits: 228185    AVG L1-dcache Misses: 2056
AVG L2 Accesses: 2273   AVG L2 Hits: 678    AVG L2 Misses: 1595
AVG L1-icache Static + Dynamic Energy:     7.33442e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.98562e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.62719e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.0963e+09 picojoules
Mean Total Runtime:                 1.082e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    582003 nanoseconds
Mean Total Energy:                  4.0555e+09 picojoules


RESULTS FOR dinfiles/023.eqntott.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 769759   AVG L1-icache Hits: 769542    AVG L1-icache Misses: 217
AVG L1-dcache Accesses: 230241   AVG L1-dcache Hits: 228185    AVG L1-dcache Misses: 2056
AVG L2 Accesses: 2273   AVG L2 Hits: 678    AVG L2 Misses: 1595
AVG L1-icache Static + Dynamic Energy:     7.33442e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.98562e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.62719e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.0963e+09 picojoules
Mean Total Runtime:                 1.082e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    582003 nanoseconds
Mean Total Energy:                  4.0555e+09 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/026.compress.din
RESULTS FOR dinfiles/026.compress.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 721216   AVG L1-icache Hits: 721093    AVG L1-icache Misses: 123
AVG L1-dcache Accesses: 278784   AVG L1-dcache Hits: 265915    AVG L1-dcache Misses: 12869
AVG L2 Accesses: 12992   AVG L2 Hits: 6914.5    AVG L2 Misses: 6077.5
AVG L1-icache Static + Dynamic Energy:     8.4628e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     7.35672e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.74007e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.94461e+09 picojoules
Mean Total Runtime:                 1.33195e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    831952 nanoseconds
Mean Total Energy:                  9.71666e+08 picojoules


RESULTS FOR dinfiles/026.compress.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 721216   AVG L1-icache Hits: 721093    AVG L1-icache Misses: 123
AVG L1-dcache Accesses: 278784   AVG L1-dcache Hits: 265915    AVG L1-dcache Misses: 12869
AVG L2 Accesses: 12992   AVG L2 Hits: 6875    AVG L2 Misses: 6117
AVG L1-icache Static + Dynamic Energy:     8.47168e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     7.3656e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.74149e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.95175e+09 picojoules
Mean Total Runtime:                 1.33373e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    833729 nanoseconds
Mean Total Energy:                  9.82001e+08 picojoules


RESULTS FOR dinfiles/026.compress.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 721216   AVG L1-icache Hits: 721093    AVG L1-icache Misses: 123
AVG L1-dcache Accesses: 278784   AVG L1-dcache Hits: 265915    AVG L1-dcache Misses: 12869
AVG L2 Accesses: 12992   AVG L2 Hits: 6824.3    AVG L2 Misses: 6167.7
AVG L1-icache Static + Dynamic Energy:     8.48309e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     7.37701e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.74332e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.9609e+09 picojoules
Mean Total Runtime:                 1.33601e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    836011 nanoseconds
Mean Total Energy:                  9.95266e+08 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/034.mdljdp2.din
RESULTS FOR dinfiles/034.mdljdp2.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 768543   AVG L1-icache Hits: 767423    AVG L1-icache Misses: 1120
AVG L1-dcache Accesses: 231457   AVG L1-dcache Hits: 230020    AVG L1-dcache Misses: 1437
AVG L2 Accesses: 2557   AVG L2 Hits: 1134.7    AVG L2 Misses: 1422.3
AVG L1-icache Static + Dynamic Energy:     7.29891e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.95619e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.61976e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.06613e+09 picojoules
Mean Total Runtime:                 1.07551e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    575509 nanoseconds
Mean Total Energy:                  4.0114e+09 picojoules


RESULTS FOR dinfiles/034.mdljdp2.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 768543   AVG L1-icache Hits: 767423    AVG L1-icache Misses: 1120
AVG L1-dcache Accesses: 231457   AVG L1-dcache Hits: 230020    AVG L1-dcache Misses: 1437
AVG L2 Accesses: 2557   AVG L2 Hits: 1136    AVG L2 Misses: 1421
AVG L1-icache Static + Dynamic Energy:     7.29862e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.9559e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.61971e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.06589e+09 picojoules
Mean Total Runtime:                 1.07545e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    575451 nanoseconds
Mean Total Energy:                  4.01106e+09 picojoules


RESULTS FOR dinfiles/034.mdljdp2.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 768543   AVG L1-icache Hits: 767423    AVG L1-icache Misses: 1120
AVG L1-dcache Accesses: 231457   AVG L1-dcache Hits: 230020    AVG L1-dcache Misses: 1437
AVG L2 Accesses: 2557   AVG L2 Hits: 1136    AVG L2 Misses: 1421
AVG L1-icache Static + Dynamic Energy:     7.29862e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.9559e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.61971e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.06589e+09 picojoules
Mean Total Runtime:                 1.07545e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    575451 nanoseconds
Mean Total Energy:                  4.01106e+09 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/039.wave5.din
RESULTS FOR dinfiles/039.wave5.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 827600   AVG L1-icache Hits: 827135    AVG L1-icache Misses: 465
AVG L1-dcache Accesses: 172400   AVG L1-dcache Hits: 172031    AVG L1-dcache Misses: 369
AVG L2 Accesses: 834   AVG L2 Hits: 91    AVG L2 Misses: 743
AVG L1-icache Static + Dynamic Energy:     7.25494e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.61694e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.65435e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.37218e+08 picojoules
Mean Total Runtime:                 1.03719e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    537188 nanoseconds
Mean Total Energy:                  3.87876e+09 picojoules


RESULTS FOR dinfiles/039.wave5.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 827600   AVG L1-icache Hits: 827135    AVG L1-icache Misses: 465
AVG L1-dcache Accesses: 172400   AVG L1-dcache Hits: 172031    AVG L1-dcache Misses: 369
AVG L2 Accesses: 834   AVG L2 Hits: 91    AVG L2 Misses: 743
AVG L1-icache Static + Dynamic Energy:     7.25494e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.61694e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.65435e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.37218e+08 picojoules
Mean Total Runtime:                 1.03719e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    537188 nanoseconds
Mean Total Energy:                  3.87876e+09 picojoules


RESULTS FOR dinfiles/039.wave5.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 827600   AVG L1-icache Hits: 827135    AVG L1-icache Misses: 465
AVG L1-dcache Accesses: 172400   AVG L1-dcache Hits: 172031    AVG L1-dcache Misses: 369
AVG L2 Accesses: 834   AVG L2 Hits: 91    AVG L2 Misses: 743
AVG L1-icache Static + Dynamic Energy:     7.25494e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.61694e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.65435e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.37218e+08 picojoules
Mean Total Runtime:                 1.03719e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    537188 nanoseconds
Mean Total Energy:                  3.87876e+09 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/047.tomcatv.din
RESULTS FOR dinfiles/047.tomcatv.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 615544   AVG L1-icache Hits: 615456    AVG L1-icache Misses: 88
AVG L1-dcache Accesses: 384456   AVG L1-dcache Hits: 374135    AVG L1-dcache Misses: 10321
AVG L2 Accesses: 10409   AVG L2 Hits: 1712.9    AVG L2 Misses: 8696.1
AVG L1-icache Static + Dynamic Energy:     8.72968e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     8.15196e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.72866e+09 picojoules
AVG DRAM Static + Dynamic Energy:   2.40834e+09 picojoules
Mean Total Runtime:                 1.43816e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    938164 nanoseconds
Mean Total Energy:                  1.53019e+09 picojoules


RESULTS FOR dinfiles/047.tomcatv.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 615544   AVG L1-icache Hits: 615456    AVG L1-icache Misses: 88
AVG L1-dcache Accesses: 384456   AVG L1-dcache Hits: 374135    AVG L1-dcache Misses: 10321
AVG L2 Accesses: 10409   AVG L2 Hits: 1764    AVG L2 Misses: 8645
AVG L1-icache Static + Dynamic Energy:     8.71819e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     8.14047e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.72682e+09 picojoules
AVG DRAM Static + Dynamic Energy:   2.39911e+09 picojoules
Mean Total Runtime:                 1.43586e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    935865 nanoseconds
Mean Total Energy:                  1.51682e+09 picojoules


RESULTS FOR dinfiles/047.tomcatv.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 615544   AVG L1-icache Hits: 615456    AVG L1-icache Misses: 88
AVG L1-dcache Accesses: 384456   AVG L1-dcache Hits: 374135    AVG L1-dcache Misses: 10321
AVG L2 Accesses: 10409   AVG L2 Hits: 1781.3    AVG L2 Misses: 8627.7
AVG L1-icache Static + Dynamic Energy:     8.7143e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     8.13658e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.72619e+09 picojoules
AVG DRAM Static + Dynamic Energy:   2.39598e+09 picojoules
Mean Total Runtime:                 1.43509e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    935086 nanoseconds
Mean Total Energy:                  1.51229e+09 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/048.ora.din
RESULTS FOR dinfiles/048.ora.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 799771   AVG L1-icache Hits: 799417    AVG L1-icache Misses: 354
AVG L1-dcache Accesses: 200231   AVG L1-dcache Hits: 199999    AVG L1-dcache Misses: 232
AVG L2 Accesses: 586   AVG L2 Hits: 44    AVG L2 Misses: 542
AVG L1-icache Static + Dynamic Energy:     7.13457e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.63572e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.61929e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.00018e+08 picojoules
Mean Total Runtime:                 1.02703e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    527028 nanoseconds
Mean Total Energy:                  3.79634e+09 picojoules


RESULTS FOR dinfiles/048.ora.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 799771   AVG L1-icache Hits: 799417    AVG L1-icache Misses: 354
AVG L1-dcache Accesses: 200231   AVG L1-dcache Hits: 199999    AVG L1-dcache Misses: 232
AVG L2 Accesses: 586   AVG L2 Hits: 44    AVG L2 Misses: 542
AVG L1-icache Static + Dynamic Energy:     7.13457e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.63572e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.61929e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.00018e+08 picojoules
Mean Total Runtime:                 1.02703e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    527028 nanoseconds
Mean Total Energy:                  3.79634e+09 picojoules


RESULTS FOR dinfiles/048.ora.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 799771   AVG L1-icache Hits: 799417    AVG L1-icache Misses: 354
AVG L1-dcache Accesses: 200231   AVG L1-dcache Hits: 199999    AVG L1-dcache Misses: 232
AVG L2 Accesses: 586   AVG L2 Hits: 44    AVG L2 Misses: 542
AVG L1-icache Static + Dynamic Energy:     7.13457e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     5.63572e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.61929e+09 picojoules
AVG DRAM Static + Dynamic Energy:   9.00018e+08 picojoules
Mean Total Runtime:                 1.02703e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    527028 nanoseconds
Mean Total Energy:                  3.79634e+09 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/085.gcc.din
RESULTS FOR dinfiles/085.gcc.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 779515   AVG L1-icache Hits: 766807    AVG L1-icache Misses: 12708
AVG L1-dcache Accesses: 220485   AVG L1-dcache Hits: 214988    AVG L1-dcache Misses: 5497
AVG L2 Accesses: 18205   AVG L2 Hits: 15465    AVG L2 Misses: 2740
AVG L1-icache Static + Dynamic Energy:     7.9749e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.57732e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.67825e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.36049e+09 picojoules
Mean Total Runtime:                 1.20522e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    705222 nanoseconds
Mean Total Energy:                  1.98993e+08 picojoules


RESULTS FOR dinfiles/085.gcc.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 779515   AVG L1-icache Hits: 766807    AVG L1-icache Misses: 12708
AVG L1-dcache Accesses: 220485   AVG L1-dcache Hits: 214988    AVG L1-dcache Misses: 5497
AVG L2 Accesses: 18205   AVG L2 Hits: 15702    AVG L2 Misses: 2503
AVG L1-icache Static + Dynamic Energy:     7.92158e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.524e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.66971e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.31768e+09 picojoules
Mean Total Runtime:                 1.19456e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    694557 nanoseconds
Mean Total Energy:                  1.36984e+08 picojoules


RESULTS FOR dinfiles/085.gcc.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 779515   AVG L1-icache Hits: 766807    AVG L1-icache Misses: 12708
AVG L1-dcache Accesses: 220485   AVG L1-dcache Hits: 214988    AVG L1-dcache Misses: 5497
AVG L2 Accesses: 18205   AVG L2 Hits: 15720.1    AVG L2 Misses: 2484.9
AVG L1-icache Static + Dynamic Energy:     7.9175e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.51993e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.66906e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.31441e+09 picojoules
Mean Total Runtime:                 1.19374e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    693742 nanoseconds
Mean Total Energy:                  1.32248e+08 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/089.su2cor.din
RESULTS FOR dinfiles/089.su2cor.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 737181   AVG L1-icache Hits: 736700    AVG L1-icache Misses: 481
AVG L1-dcache Accesses: 262819   AVG L1-dcache Hits: 259684    AVG L1-dcache Misses: 3135
AVG L2 Accesses: 3616   AVG L2 Hits: 687.5    AVG L2 Misses: 2928.5
AVG L1-icache Static + Dynamic Energy:     7.58322e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.39732e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.64263e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.34202e+09 picojoules
Mean Total Runtime:                 1.14805e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    648054 nanoseconds
Mean Total Energy:                  8.77341e+07 picojoules


RESULTS FOR dinfiles/089.su2cor.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 737181   AVG L1-icache Hits: 736700    AVG L1-icache Misses: 481
AVG L1-dcache Accesses: 262819   AVG L1-dcache Hits: 259684    AVG L1-dcache Misses: 3135
AVG L2 Accesses: 3616   AVG L2 Hits: 700    AVG L2 Misses: 2916
AVG L1-icache Static + Dynamic Energy:     7.58041e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.39451e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.64218e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.33976e+09 picojoules
Mean Total Runtime:                 1.14749e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    647492 nanoseconds
Mean Total Energy:                  8.44636e+07 picojoules


RESULTS FOR dinfiles/089.su2cor.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 737181   AVG L1-icache Hits: 736700    AVG L1-icache Misses: 481
AVG L1-dcache Accesses: 262819   AVG L1-dcache Hits: 259684    AVG L1-dcache Misses: 3135
AVG L2 Accesses: 3616   AVG L2 Hits: 700    AVG L2 Misses: 2916
AVG L1-icache Static + Dynamic Energy:     7.58041e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.39451e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.64218e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.33976e+09 picojoules
Mean Total Runtime:                 1.14749e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    647492 nanoseconds
Mean Total Energy:                  8.44636e+07 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/090.hydro2d.din
RESULTS FOR dinfiles/090.hydro2d.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 748688   AVG L1-icache Hits: 747801    AVG L1-icache Misses: 887
AVG L1-dcache Accesses: 251312   AVG L1-dcache Hits: 239377    AVG L1-dcache Misses: 11935
AVG L2 Accesses: 12822   AVG L2 Hits: 6356.8    AVG L2 Misses: 6465.2
AVG L1-icache Static + Dynamic Energy:     8.61488e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     7.37144e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.7815e+09 picojoules
AVG DRAM Static + Dynamic Energy:   2.01403e+09 picojoules
Mean Total Runtime:                 1.34863e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    848633 nanoseconds
Mean Total Energy:                  1.0992e+09 picojoules


RESULTS FOR dinfiles/090.hydro2d.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 748688   AVG L1-icache Hits: 747801    AVG L1-icache Misses: 887
AVG L1-dcache Accesses: 251312   AVG L1-dcache Hits: 239377    AVG L1-dcache Misses: 11935
AVG L2 Accesses: 12822   AVG L2 Hits: 6530.4    AVG L2 Misses: 6291.6
AVG L1-icache Static + Dynamic Energy:     8.57582e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     7.33238e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.77525e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.98267e+09 picojoules
Mean Total Runtime:                 1.34082e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    840821 nanoseconds
Mean Total Energy:                  1.05378e+09 picojoules


RESULTS FOR dinfiles/090.hydro2d.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 748688   AVG L1-icache Hits: 747801    AVG L1-icache Misses: 887
AVG L1-dcache Accesses: 251312   AVG L1-dcache Hits: 239377    AVG L1-dcache Misses: 11935
AVG L2 Accesses: 12822   AVG L2 Hits: 6533.3    AVG L2 Misses: 6288.7
AVG L1-icache Static + Dynamic Energy:     8.57517e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     7.33173e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.77515e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.98215e+09 picojoules
Mean Total Runtime:                 1.34069e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    840691 nanoseconds
Mean Total Energy:                  1.05302e+09 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/093.nasa7.din
RESULTS FOR dinfiles/093.nasa7.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 802971   AVG L1-icache Hits: 802508    AVG L1-icache Misses: 463
AVG L1-dcache Accesses: 197029   AVG L1-dcache Hits: 194154    AVG L1-dcache Misses: 2875
AVG L2 Accesses: 3338   AVG L2 Hits: 367    AVG L2 Misses: 2971
AVG L1-icache Static + Dynamic Energy:     7.75101e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.23615e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.70994e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.3487e+09 picojoules
Mean Total Runtime:                 1.14872e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    648716 nanoseconds
Mean Total Energy:                  1.62391e+08 picojoules


RESULTS FOR dinfiles/093.nasa7.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 802971   AVG L1-icache Hits: 802508    AVG L1-icache Misses: 463
AVG L1-dcache Accesses: 197029   AVG L1-dcache Hits: 194154    AVG L1-dcache Misses: 2875
AVG L2 Accesses: 3338   AVG L2 Hits: 367    AVG L2 Misses: 2971
AVG L1-icache Static + Dynamic Energy:     7.75101e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.23615e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.70994e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.3487e+09 picojoules
Mean Total Runtime:                 1.14872e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    648716 nanoseconds
Mean Total Energy:                  1.62391e+08 picojoules


RESULTS FOR dinfiles/093.nasa7.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 802971   AVG L1-icache Hits: 802508    AVG L1-icache Misses: 463
AVG L1-dcache Accesses: 197029   AVG L1-dcache Hits: 194154    AVG L1-dcache Misses: 2875
AVG L2 Accesses: 3338   AVG L2 Hits: 367    AVG L2 Misses: 2971
AVG L1-icache Static + Dynamic Energy:     7.75101e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.23615e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.70994e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.3487e+09 picojoules
Mean Total Runtime:                 1.14872e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    648716 nanoseconds
Mean Total Energy:                  1.62391e+08 picojoules


========================================================================================================
RUNNING CACHE SIM ON dinfiles/094.fpppp.din
RESULTS FOR dinfiles/094.fpppp.din WITH L2 CACHE SET ASSOCIATIVITY = 2
AVG L1-icache Accesses: 700500   AVG L1-icache Hits: 692732    AVG L1-icache Misses: 7768
AVG L1-dcache Accesses: 299500   AVG L1-dcache Hits: 294125    AVG L1-dcache Misses: 5375
AVG L2 Accesses: 13143   AVG L2 Hits: 10806.3    AVG L2 Misses: 2336.7
AVG L1-icache Static + Dynamic Energy:     7.57272e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.57022e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.58469e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.26942e+09 picojoules
Mean Total Runtime:                 1.16429e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    664295 nanoseconds
Mean Total Energy:                  4.2684e+09 picojoules


RESULTS FOR dinfiles/094.fpppp.din WITH L2 CACHE SET ASSOCIATIVITY = 4
AVG L1-icache Accesses: 700500   AVG L1-icache Hits: 692732    AVG L1-icache Misses: 7768
AVG L1-dcache Accesses: 299500   AVG L1-dcache Hits: 294125    AVG L1-dcache Misses: 5375
AVG L2 Accesses: 13143   AVG L2 Hits: 10935.1    AVG L2 Misses: 2207.9
AVG L1-icache Static + Dynamic Energy:     7.54374e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.54124e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.58005e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.24615e+09 picojoules
Mean Total Runtime:                 1.1585e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    658499 nanoseconds
Mean Total Energy:                  4.2347e+09 picojoules


RESULTS FOR dinfiles/094.fpppp.din WITH L2 CACHE SET ASSOCIATIVITY = 8
AVG L1-icache Accesses: 700500   AVG L1-icache Hits: 692732    AVG L1-icache Misses: 7768
AVG L1-dcache Accesses: 299500   AVG L1-dcache Hits: 294125    AVG L1-dcache Misses: 5375
AVG L2 Accesses: 13143   AVG L2 Hits: 10938    AVG L2 Misses: 2205
AVG L1-icache Static + Dynamic Energy:     7.54309e+08 picojoules
AVG L1-dcache Static + Dynamic Energy:     6.54059e+08 picojoules
AVG L2 Static + Dynamic Energy:     1.57995e+09 picojoules
AVG DRAM Static + Dynamic Energy:   1.24563e+09 picojoules
Mean Total Runtime:                 1.15837e+06 nanoseconds
Mean Time L1 + L2 + DRAM Active (Total access time):    658368 nanoseconds
Mean Total Energy:                  4.23394e+09 picojoules


========================================================================================================