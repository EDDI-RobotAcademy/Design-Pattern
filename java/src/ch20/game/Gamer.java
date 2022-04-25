package ch20.game;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Gamer {
    private int money;
    private List<String> fruits = new ArrayList<>();
    private Random random = new Random();

    private static String[] fruitsName = {
            "사과", "포도", "바나나", "귤",
    };

    public Gamer(int money) {
        this.money = money;
    }

    public int getMoney() {
        return money;
    }

    public void bet() {
        int dice = random.nextInt(6) + 1;
        if (dice == 1) {
            money += 100;
            System.out.println("소지금 증가!");
        } else if (dice == 2) {
            money /= 2;
            System.out.println("소지금이 절반!");
        } else if (dice == 6) {
            String f = getFruit();
            System.out.println("과일(" + f + ") 획득!");
            fruits.add(f);
        } else {
            System.out.println("아무일 없음!");
        }
    }

    public Memento createMemento() {
        Memento m = new Memento(money);
        for (String f: fruits) {
            if (f.startsWith("맛있는")) {
                m.addFruit(f);
            }
        }
        return m;
    }

    public void restoreMemento(Memento memento) {
        this.money = memento.getMoney();
        this.fruits = memento.getFruits();
    }

    @Override
    public String toString() {
        return "[money = " + money + ", fruits = " + fruits + "]";
    }

    private String getFruit() {
        String f = fruitsName[random.nextInt(fruitsName.length)];
        if (random.nextBoolean()) {
            return "맛있는" + f;
        } else {
            return f;
        }
    }
}
