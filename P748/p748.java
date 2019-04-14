import java.io.IOException;
import java.math.BigDecimal;

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
    String line;
    String[] parts;
    BigDecimal bDec;
    String frac;
    String ex;
    while ((line = Main.readln(16)) != null) {
      frac = line.substring(0, 6);
      ex = line.substring(7,9).trim();
      //System.out.println("'" + frac + "','" + ex + "'");
      bDec = new BigDecimal(frac);
      bDec = bDec.pow(Integer.parseInt(ex));
      line = bDec.stripTrailingZeros().toPlainString();
      if (line.charAt(0) == '0' && line.charAt(1) == '.')
        line = line.substring(1);
      System.out.println(line);
    }
  }
}
