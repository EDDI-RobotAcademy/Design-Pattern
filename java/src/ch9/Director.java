package ch9;

public class Director {
    private Builder builder;

    // 생성자
    public Director(Builder builder) {
        this.builder = builder;
    }

    // 문서 만들기
    public void construct() {
        builder.makeTitle("Greeting");
        builder.makeString("일반적인 인사");
        builder.makeItems(new String[]{
                "How are you?",
                "Hello.",
                "Hi.",
        });
        builder.makeString("시간대에 따른 인사");
        builder.makeItems(new String[]{
                "Good morning.",
                "Good afternoon.",
                "Good evening.",
        });
        builder.close();
    }
}
