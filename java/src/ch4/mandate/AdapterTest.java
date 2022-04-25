package ch4.mandate;

import ch4.Writer;

public class AdapterTest {
    public static void main(String[] args) {
        Writer p = new WriteBanner("Hello");
        p.writeWeak();
        p.writeStrong();
    }
}
