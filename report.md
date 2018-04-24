# James Doyle - Homework 7

**P1:**
Most of my graph-building algorithm occurs through my creation of three nested
"for" loops. As such, the complexity of this solution if tied to these  loops.
As the first loop is iterating across all groups (G), has nested in it a loop
iterating across all members of each group (K), and that second loop has nested
in it another loop iterating across all members of each group (K), the complexity
of the algorithm is O(GK^2).

**P3:**
I tried benchmarking for p2_main and p3_main, but kept getting a floating point
exception error. Upon inspection, I realized that it was because for some reason
the git repository made for this assignment that I got to via piazza had the
events.csv test data input file, but not the other data. As such, no group
or member data is successfully loaded by the LoadData event and, subsequently,
the modulo (%) operation in the RandomizeGraph function fails. As I couldn't 
successfully find the members.csv or groups.csv anywhere, I will just theorize 
about the results.

The BFS likely reports a better time performance than the IDDFS algorithm,
due to the generally speedier and quicker-concludinging nature of the BFS 
algorithm over that of DFS. The IDDFS algorithm, though, likely uses up less
space than the BFS algorithm due to the low memory consumption nature of DFS,
causing the IDDFS' peak memory consumption to be reported as lower than that of
the BFS.

**Note:**
I completely forgot this homework was due, so I sadly ran out of time to do P4
(i.e. decided I should study for the final instead of spending time grappling
with it). Honest apologies, it was my bad.