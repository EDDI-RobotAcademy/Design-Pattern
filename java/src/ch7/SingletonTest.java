package ch7;

public class SingletonTest {
    public static void main(String[] args) {
        System.out.println("Start.");
        Singleton obj1 = Singleton.getInstance();
        Singleton obj2 = Singleton.getInstance();
        if (obj1 == obj2) {
            System.out.println("obj1 과 obj2 는 같습니다.");
        } else {
            System.out.println("obj1 과 obj2 는 같지 않습니다.");
        }
        System.out.println("End.");
    }
}
