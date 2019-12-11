


import org.hibernate.Session;

import java.util.Date;

public class Main2 {

	public static void main(String[] args) {

		System.out.println("Hibernate one to many (Annotation)");
		
		Session session = hibernate.HibernateUtil.getSessionFactory().openSession();

		session.beginTransaction();
		
		hibernate.Beer beer1 = new hibernate.Beer();
		beer1.setName("Dreher");
		beer1.setExpirationDate(new Date());

		hibernate.Beer beer2 = new hibernate.Beer();
		beer2.setName("Kozel");
		beer2.setExpirationDate(new Date());

		hibernate.Beer beer3 = new hibernate.Beer();
		beer3.setName("HB");
		beer3.setExpirationDate(new Date());

		hibernate.Beer beer4 = new hibernate.Beer();
		beer4.setName("Borsodi");
		beer4.setExpirationDate(new Date());

		hibernate.Beer beer5 = new hibernate.Beer();
		beer5.setName("Stella");
		beer5.setExpirationDate(new Date());

		hibernate.Beer beer6 = new hibernate.Beer();
		beer6.setName("Staropramen");
		beer6.setExpirationDate(new Date());

		hibernate.BeerFactory factory1 = new hibernate.BeerFactory();
		factory1.setCity("Budapest");
		factory1.setName("Borsodi Sörgyár");

		hibernate.BeerFactory factory2 = new hibernate.BeerFactory();
		factory2.setCity("Budapest");
		factory2.setName("Dreher Sörgyár");


		beer1.setBeerFactory(factory1);
		beer2.setBeerFactory(factory1);
		beer3.setBeerFactory(factory1);
		beer4.setBeerFactory(factory1);
		
		beer5.setBeerFactory(factory2);
		beer6.setBeerFactory(factory2);

		session.save(beer1);
		session.save(beer2);
		session.save(beer3);
		session.save(beer4);
		session.save(beer5);
		session.save(beer6);
		session.save(factory1);
		session.save(factory2);
		session.getTransaction().commit();
		hibernate.HibernateUtil.shutdown();

		System.out.println("Done");
	}
}
