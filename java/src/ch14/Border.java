package ch14;

public abstract class Border extends Display {
    protected Display display;

    protected Border(Display display) {
        this.display = display;
    }
}
