ackage pl.shad.net.blog;
 
/**
 * Interfejs dostępu do danych
 */
interface ImageInterface{
	String getImage();
}
 
/**
 * Główna klasa generująca dane
 */
class Image implements ImageInterface{
 
	@Override
	public String getImage(){
		return "HiRes image data ...";
	}
}
 
/**
 * Klasa proxy, przy pierwszym wywołaniu
 * daje dane poglądowe
 */
class ProxyImage implements ImageInterface{
 
	private Image image;
	private int counter = 0;
 
	@Override
	public String getImage(){
 
		counter++;
		if (counter > 1){
			if (image == null){
				image = new Image();
			}
			return image.getImage();
		}
		return "LoRes proxy thumbnail ...";
	}
}
 
/**
 * Testowa klasa uruchomieniowa
 */
public class DesignPatternsProxy{
 
	public static void main(String[] args){
 
		//
		// Odwołania do głównego obiektu bez użycia proxy
		//
		ImageInterface image = new Image();
		System.out.println("Object without proxy:");
		System.out.println("First access: " + image.getImage());
		System.out.println("Second access: " + image.getImage());
 
		//
		// Odwołania do głównego obiektu z użyciem obiektu proxy
		//
		image = new ProxyImage();
		System.out.println("Object with proxy:");
		System.out.println("First access: " + image.getImage());
		System.out.println("Second access: " + image.getImage());
	}
}