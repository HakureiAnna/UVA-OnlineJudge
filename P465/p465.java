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
    BigInteger lim = new BigInteger(Integer.toString(Integer.MAX_VALUE)),
      x, y, result;
    String line;
    String[] comps;
    while ((line = Main.readln(1000)) != null) {
      comps = line.split(" ");
      x = new BigInteger(comps[0]);
      y = new BigInteger(comps[2]);
      if (comps[1].charAt(0) == '*')
        result = x.multiply(y);
      else
        result = x.add(y);
      System.out.println(line);
      if (lim.compareTo(x) < 0)
        System.out.println("first number too big");
      if (lim.compareTo(y) < 0)
        System.out.println("second number too big");
      if (lim.compareTo(result) < 0)
        System.out.println("result too big");
    }
  }
}
