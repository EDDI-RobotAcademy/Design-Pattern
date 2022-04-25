package ch4.inheritance;

import ch4.Banner;
import ch4.Writer;

public class WriteBanner extends Banner implements Writer {

    public WriteBanner(String string) {
        super(string);
    }

    @Override
    public void writeWeak() {
        showWithParen();
    }

    @Override
    public void writeStrong() {
        showWithAster();
    }
}
