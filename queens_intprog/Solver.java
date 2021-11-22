/**
 *Solves the queens puzzle for n queens on a nxn chessboard.
 * See https://en.wikipedia.org/wiki/Eight_queens_puzzle/
 *
 * @author Joas Haunstrup and Daniel Lundgaard
 * @version 28-10-2020
 */
public class Solver {
    private int noOfQueens;
    private int bitCol, bitDia1, bitDia2;
    private int noOfSolutions;
    private final String stars = "*".repeat(48);

    /**
     * For each number in a given interval, find the number of solutions with that many queens.
     * Print the following to the terminal for each number in the interval: the number, the number of solutions,
     * the time to find the solutions (in ms), and the average time used to find each solution (in ms).
     * To avoid division by 0, the time is set to 1 if it is 0.
     * @param min The lower bound of the interval.
     * @param max The upper bound of the interval.
     */
    public void findNoOfSolutions(int min, int max) {
        System.out.println(stars);
        System.out.format("%6s  %12s   %10s   %12s %n", "Queens", "Solutions", "Time (ms)", "Solutions/ms");
        for(int i = min; i <= max; i++) {
            noOfQueens = i;
            noOfSolutions = bitCol = bitDia1 = bitDia2 = 0;
            long start = System.currentTimeMillis();
            positionQueens(0);
            noOfSolutions *= 2;
            if (noOfQueens%2 > 0) {
                bitCol = 1 << (noOfQueens/2);
                bitDia1 = 1 << (noOfQueens/2);
                bitDia2 = 1 << (noOfQueens/2);
                positionQueens(1);
            }
            long duration = Math.max(System.currentTimeMillis() - start, 1);
            System.out.format("%6d  %,12d   %,10d   %,12d %n", noOfQueens, noOfSolutions, duration, noOfSolutions/duration );
        }
        System.out.println(stars + "\n");
    }

    /**
     *Place a queen on the first legal spot in a given row.
     * With recursion gives all solutions for a given number of queens.
     * @param row The row in which to look for a place to put a queen.
     */
    private void positionQueens(int row) {
        if (row == noOfQueens)
            noOfSolutions++;
        else
            for(int i = 0; i < (row == 0 ? noOfQueens/2 : noOfQueens); i++) {
                if(0 == ((1<<i)&bitCol) + ((1<<(row+i))&bitDia1) + ((1<<(row-i+noOfQueens-1))&bitDia2)) {
                    bitCol |= 1<<i;
                    bitDia1 |= 1<<(row+i);
                    bitDia2 |= 1<<(row-i+noOfQueens-1);
                    positionQueens(row + 1);
                    bitCol ^= 1<<i;
                    bitDia1 ^= 1<<(row+i);
                    bitDia2 ^= 1<<(row-i+noOfQueens-1);
                }
            }
    }

    /**
     * Test the functionality of the Solver class.
     */
    public static void testSolver() {
        Solver test = new Solver();
        test.findNoOfSolutions(1, 16);
    }

    public static void main(String[] args) {
        Solver.testSolver();
    }
}
