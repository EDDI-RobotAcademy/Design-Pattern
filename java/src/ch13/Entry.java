package ch13;

public abstract class Entry {
    public abstract String getName();
    public abstract int getSize();

    public void printList() {
        printList("");
    }

    // prefix를 앞에 붙여 목록을 표시합니다.
    protected abstract void printList(String prefix);

    // 문자열 표현
    @Override
    public String toString() {
        return getName() + " (" + getSize() + ")";
    }
}
