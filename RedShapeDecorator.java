public interface Shape{
		
		void Draw();
	}

public class Square implements Shape {

	@Override
	public void Draw() {
		System.out.println("rysowanie");
		
	}

}
public abstract class ShapeDecorator implements Shape {
	protected Shape decoratedShape;
	public ShapeDecorator( Shape decoratedShape){
		this.decoratedShape = decoratedShape;
	}
	public void Draw(){
		decoratedShape.Draw();
	}
}

public class RedShapeDecorator extends ShapeDecorator {

		   public RedShapeDecorator(Shape decoratedShape) {
		      super(decoratedShape);		
		   }

		   @Override
		   public void Draw() {
		      decoratedShape.Draw();	       
		      setRedBorder(decoratedShape);
		   }

		   private void setRedBorder(Shape decoratedShape){
		      System.out.println("czerwony kolor");
		   }
		}


   public static void main() {
 Shape CzerwonyKwadrat= new RedShapeDecorator(new Square());
     

     
      CzerwonyKwadrat.Draw();
   }
