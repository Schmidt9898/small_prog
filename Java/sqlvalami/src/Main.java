import org.hibernate.SessionFactory;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;
import org.hibernate.cfg.Configuration;
import org.hibernate.service.ServiceRegistry;
import org.hibernate.*;

import java.sql.SQLException;
import java.util.Date;
import java.util.Iterator;
import java.util.List;
import java.util.Locale;

public class Main {

            public static void main(String[] args) throws SQLException, ClassNotFoundException {
               /* System.out.println("Hello World!");

                SessionFactory sessionFactory;

                Configuration configuration=new Configuration();
                configuration.configure();

                sessionFactory = configuration.buildSessionFactory();




                Session ss= sessionFactory.openSession();
                ss.beginTransaction();
                for(int i=0;i<100;i++){
                    Date a = new Date(System.currentTimeMillis());

                    blogentry b= new blogentry("nev"+i,"commentelekvalamit",a);
                    blogentrycomment bc = new blogentrycomment("ez a commentem"+i,a);
                    bc.setFkey(b);
                    ss.save(b);
                    ss.save(bc);


                }




                ss.getTransaction().commit();
                ss.close();




                sessionFactory.close();


*/

                System.out.println("Hibernate one to many (Annotation)");

                Session session = hibernate.HibernateUtil.getSessionFactory().openSession();

                session.beginTransaction();

                hibernate.Beer beer1 = new hibernate.Beer();
                beer1.setName("Dreher");
                beer1.setExpirationDate(new java.util.Date());

                hibernate.Beer beer2 = new hibernate.Beer();
                beer2.setName("Kozel");
                beer2.setExpirationDate(new java.util.Date());

                hibernate.Beer beer3 = new hibernate.Beer();
                beer3.setName("HB");
                beer3.setExpirationDate(new java.util.Date());

                hibernate.Beer beer4 = new hibernate.Beer();
                beer4.setName("Borsodi");
                beer4.setExpirationDate(new java.util.Date());

                hibernate.Beer beer5 = new hibernate.Beer();
                beer5.setName("Stella");
                beer5.setExpirationDate(new java.util.Date());

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

