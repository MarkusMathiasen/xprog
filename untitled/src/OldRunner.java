public class OldRunner implements Runnable {
    private int bitCol;
    private int bitDia1;
    private int bitDia2;
    final private Callback callback;
    final private int noOfQueens;
    private int startCol;
    private int solutions = 0;

    OldRunner(int bitCol, int bitDia1, int bitDia2, Callback callback, int noOfQueens, int startCol) {
        this.bitCol = bitCol;
        this.bitDia1 = bitDia1;
        this.bitDia2 = bitDia2;
        this.callback = callback;
        this.noOfQueens = noOfQueens;
        this.startCol = startCol;
    }

    @Override
    public void run() {
        positionQueens(1);
        callback.whenDone(noOfQueens%2 == 1 && startCol == noOfQueens/2 ? solutions : solutions*2);
    }
    private void positionQueens(int row) {
        if (row == noOfQueens)
            solutions++;
        else
            for(int col = 0; col < noOfQueens; col++)
                if(0 == ((1<<col)&bitCol) + ((1<<(row+col))&bitDia1) + ((1<<(row-col+noOfQueens-1))&bitDia2)) {
                    bitCol |= 1<<col;
                    bitDia1 |= 1<<(row+col);
                    bitDia2 |= 1<<(row-col+noOfQueens-1);
                    positionQueens(row + 1);
                    bitCol ^= 1<<col;
                    bitDia1 ^= 1<<(row+col);
                    bitDia2 ^= 1<<(row-col+noOfQueens-1);
                }
    }
}