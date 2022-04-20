package ch7;

public class ThreadSingleton {
    private static ThreadSingleton singleton = null;

    private ThreadSingleton() {
        System.out.println("객체 생성!");
        slowdown();
    }

    public static synchronized ThreadSingleton getInstance() {
        if (singleton == null) {
            singleton = new ThreadSingleton();
        }
        return singleton;
    }

    private void slowdown() {
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
        }
    }
}
