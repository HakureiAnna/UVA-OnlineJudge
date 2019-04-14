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
    String line;
    int i;
    BigInteger x, y, result;
    char op;

    while ((line = Main.readln(1024)) != null) {
      for (i = 0; i < line.length(); ++i)
        if (line.charAt(i) == ' ')
          break;
      x = new BigInteger(line.substring(0, i));

      for (i++; i < line.length(); ++i)
        if (line.charAt(i) != ' ')
          break;
      op = line.charAt(i);

      for (i++; i < line.length(); ++i)
        if (line.charAt(i) != ' ')
          break;
      y = new BigInteger(line.substring(i));

      if (op == '/')
        result = x.divide(y);
      else
        result = x.mod(y);
      System.out.println(result);
    }
  }
}
