import java.util.ArrayList;

/**
 *Solves the queens puzzle for n queens on a nxn chessboard.
 * See https://en.wikipedia.org/wiki/Eight_queens_puzzle/
 *
 * @author Joas Haunstrup and Daniel Lundgaard
 * @version 28-10-2020
 */
public class Solver implements Callback {
    private int noOfQueens;
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
            noOfSolutions = 0;
            long start = System.currentTimeMillis();
            positionQueens();
            long duration = Math.max(System.currentTimeMillis() - start, 1);
            System.out.format("%6d  %,12d   %,10d   %,12d %n", noOfQueens, noOfSolutions, duration, noOfSolutions/duration );
        }
        System.out.println(stars + "\n");
    }

    public void positionQueens() {
        ArrayList<Thread> threads = new ArrayList<>();
        for (int col = 0; col < noOfQueens/2 + (noOfQueens%2); col++)
            threads.add(new Thread(new Runner(1<<col, 1<<col, 1<<(-col+noOfQueens-1), this, noOfQueens, col), ""+col));
        for (Thread t : threads)
            t.start();
        for (Thread t : threads) {
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public synchronized void whenDone(int solutions) {
        noOfSolutions += solutions;
    }

    /**
     * Test the functionality of the Solver class.
     */
    public static void testSolver() {
        Solver test = new Solver();
        test.findNoOfSolutions(1, 17);
    }

    public static void main(String[] args) {
        Solver.testSolver();
    }
}
