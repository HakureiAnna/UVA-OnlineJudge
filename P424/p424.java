import java.math.BigInteger;
import java.io.IOException;

class Main {
  static String readln(int maxLen) {
    byte line[] = new byte[maxLen];
    int len = 0, ch = -1;
    String str = "";

    try {
      while (len < maxLen) {
        ch = System.in.read();
        if (ch < 0 || ch == '\n') break;
        line[len++] = (byte)ch;
      }
    } catch (IOException e) {
      return null;
    }

    if (ch < 0 && len == 0) return null;  // eof
    return new String(line, 0, len);
  }

  public static void main(String[] args) {
    (new Main()).run();
  }

  public void run() {
    BigInteger sum = new BigInteger("0");
    while (true) {
      String str = Main.readln(101);
      //System.out.println(str);
      if  (str.length() == 1 && str.charAt(0) == '0')
        break;
      sum = sum.add(new BigInteger(str));
    }
    System.out.println(sum);
  }
}
