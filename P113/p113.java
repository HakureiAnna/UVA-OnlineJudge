import java.io.IOException;
import java.math.BigInteger;

class Main {
  static String readln(int maxLen) {
    byte line[] = new byte[maxLen];
    int len = 0, ch = -1;
    String str = "";

    try {
      while (len < maxLen) {
        ch = System.in.read();
        if (ch < 0 || ch == '\n')
           break;
        line[len++] = (byte)ch;
      }
    } catch (IOException e) {
      return null;
    }

    if (ch < 0 && len == 0)
      return null;  // eof
    return new String(line, 0, len);
  }

  public static void main(String[] args) {
    (new Main()).run();
  }

  public void run() {
    String sPower;
    String sExp;

    while ((sExp = Main.readln(1024)) != null) {
      sPower = Main.readln(1024);
      int n = Integer.parseInt(sExp);
      BigInteger p = new BigInteger(sPower);
      BigInteger high = p;
      BigInteger low = BigInteger.ONE;
      BigInteger mid = null;
      BigInteger two = BigInteger.ONE.add(BigInteger.ONE);
      int cmp;
      while (low.compareTo(high) <= 0) {
        mid = low.add(high).divide(two);
        cmp = mid.pow(n).compareTo(p);
        if (cmp > 0) {
          high = mid.subtract(BigInteger.ONE);
        } else if (cmp < 0) {
          low = mid.add(BigInteger.ONE);
        } else
          break;
      }
      System.out.println(mid);

    }
  }
}
