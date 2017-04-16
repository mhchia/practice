package pond.duck;
public class MuteQuack implements QuackBehavior
{
    public void quack()
    {
        // do nothing, cannot quack
        System.out.println("<< Silence >>");
    }
}
