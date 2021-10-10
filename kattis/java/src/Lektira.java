import java.util.*;

public class Lektira {
    static Kattio io = new Kattio(System.in);
    public static void main(String[] args) {
        String s = io.getString();
        String res = "z".repeat(50);
        for (int a = 1; a < s.length()-1; a++)
            for (int b = a+1; b < s.length(); b++) {
                StringBuilder x = new StringBuilder(s.substring(0, a));
                StringBuilder y = new StringBuilder(s.substring(a, b));
                StringBuilder z = new StringBuilder(s.substring(b));
                x.reverse();
                y.reverse();
                z.reverse();
                String att = x.toString() + y.toString() + z.toString();
                if (att.compareTo(res) < 0)
                    res = att;
            }
        System.out.println(res);
    }
}
