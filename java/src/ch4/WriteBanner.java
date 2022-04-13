package ch4;

public class WriteBanner implements Writer {
    private Banner banner;

    public WriteBanner(String string) {
        this.banner = new Banner(string);
    }

    @Override
    public void writeWeak() {
        banner.showWithParen();
    }

    @Override
    public void writeStrong() {
        banner.showWithAster();
    }
}
