package pond.duck;
public class FlyNoWay implements FlyBehavior
{
    public void fly()
    {
        // do nothing, cannot fly
        System.out.println("I can't fly");
    }
}
