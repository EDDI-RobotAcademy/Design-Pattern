package ch7;

public class SingletonTest3 extends Thread {
    public static void main(String[] args) {
        System.out.println("Start.");
        new SingletonTest3("A").start();
        new SingletonTest3("B").start();
        new SingletonTest3("C").start();
        System.out.println("End.");
    }

    @Override
    public void run() {
        Singleton obj = Singleton.getInstance();
        System.out.println(getName() + ": obj = " + obj);
    }

    public SingletonTest3(String name) {
        super(name);
    }
}
