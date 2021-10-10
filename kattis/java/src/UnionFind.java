import java.io.*;
import java.util.*;

public class UnionFind {
    public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter out = new PrintWriter(System.out);
    public static int[] uf;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        uf = new int[n];
        for (int i = 0; i < n; i++)
            uf[i] = i;
        while (q-- > 0) {
            st = new StringTokenizer(in.readLine());
            String op = st.nextToken();
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if (op.equals("="))
                uf[find(y)] = uf[find(x)];
            else
                out.println(find(x) == find(y) ? "yes" : "no");
        }
        out.flush();
    }

    private static int find(int x) {
        if (uf[x] == x)
            return x;
        return uf[x] = find(uf[x]);
    }
}
