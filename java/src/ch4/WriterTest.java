package ch4;

public class WriterTest {
    public static void main(String[] args) {
        Writer p = new WriteBanner("Hello");
        p.writeWeak();
        p.writeStrong();
    }
}
