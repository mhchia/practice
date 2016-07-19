/*
 * not IoC
 * TextEditor depends on SpellChecker
 *
class SpellChecker {

    private String rule;
    public SpellChecker() {
    }
    public boolean spellCheck(String s) {
        return true;
    }
}

class TextEditor {
    private SpellChecker checker;
    public TextEditor() {
        checker = new SpellChecker();
    }
    public boolean addText(String s) {
        return checker.spellCheck(s);
    }
    public static void main(String[] args) {
        TextEditor te = new TextEditor();
        System.out.println(te.addText("YOOOOO"));
    }
}
*/

/*
 * IoC
 * The client creating the TextEditor class has the control over which SpellChecker implementation to use.
 * Therefore, we're injecting the TextEditor with the dependency
 */
interface ISpellChecker {
    public void spellCheck(String s);
}

class SpellCheckerA implements ISpellChecker {
    public void spellCheck(String s) {

    }
}

class TextEditor {
    private ISpellChecker checker;
    public TextEditor(ISpellChecker checker) {
        this.checker = checker;
    }
    public static void main(String[] s) {
        SpellCheckerA sca = new SpellCheckerA();
        TextEditor te = new TextEditor(sca);
    }
}
