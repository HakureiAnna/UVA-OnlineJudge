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
    String str;
    BigInteger x;
    while ((str = Main.readln(256)) != null) {
      x = new BigInteger(str);
      str = Main.readln(256);
      System.out.println(x.multiply(new BigInteger(str)));
    }
  }
}
