package ch5;

public interface DisplayInterface {
    public abstract void open();
    public abstract void print();
    public abstract void close();

    public default void display() {
        open();
        for (int i = 0; i < 5; i++) {
            print();
        }
        close();
    }
}
