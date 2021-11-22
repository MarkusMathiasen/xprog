import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Stack;

public class Runner2 implements Runnable {
    private int bitCol;
    private int bitDia1;
    private int bitDia2;
    final private Callback callback;
    final private int noOfQueens;
    private int startCol;
    private int solutions = 0;

    Runner2(int bitCol, int bitDia1, int bitDia2, Callback callback, int noOfQueens, int startCol) {
        this.bitCol = bitCol;
        this.bitDia1 = bitDia1;
        this.bitDia2 = bitDia2;
        this.callback = callback;
        this.noOfQueens = noOfQueens;
        this.startCol = startCol;
    }

    @Override
    public void run() {
        positionQueens(1, bitCol, bitDia1, bitDia2);
        callback.whenDone(noOfQueens%2 == 1 && startCol == noOfQueens/2 ? solutions : solutions*2);
    }
    private void positionQueens(int row, int a, int b, int c) {
        ArrayList<int[]> s = new ArrayList<>();
        s.add(new int[]{row, a, b, c});
        while (!s.isEmpty()) {
            int[] A = s.remove(s.size()-1);
            row = A[0];
            if (row == noOfQueens) {
                solutions++;
                continue;
            }
            a = A[1]; b = A[2]; c = A[3];
            for(int col = 0; col < noOfQueens; col++)
                if(0 == ((1<<col)&a) + ((1<<(row+col))&b) + ((1<<(row-col+noOfQueens-1))&c))
                    s.add(new int[]{row + 1, a|(1<<col), b|(1<<(row+col)), c|(1<<(row-col+noOfQueens-1))});
        }

    }
}
