package ch20;

import ch20.game.Gamer;
import ch20.game.Memento;

public class MementoTest {
    public static void main(String[] args) {
        Gamer gamer = new Gamer(100);
        Memento memento = gamer.createMemento();

        System.out.println("시작!");

        for (int i = 0; i < 100; i++) {
            System.out.println("==== " + i);
            System.out.println("상태:" + gamer);

            gamer.bet();

            System.out.println("소지금은 " + gamer.getMoney() + "원 입니다.");

            if (gamer.getMoney() > memento.getMoney()) {
                System.out.println("상태 보존!");
                memento = gamer.createMemento();
            } else if (gamer.getMoney() < memento.getMoney() / 2) {
                System.out.println("상태 복원!");
                gamer.restoreMemento(memento);
            }

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
            }
            System.out.println();
        }
    }
}
