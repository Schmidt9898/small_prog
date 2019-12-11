package hibernate;

import java.util.HashSet;
import java.util.Set;

import javax.persistence.*;

@Entity
@Table(name = "BeerFactory")
public class BeerFactory {

	private int id;
	private String city;
	private String name;
	private Set<hibernate.Beer> beers = new HashSet<hibernate.Beer>(0);

	@Id
    @Column(name = "BEERFACTORY_ID")
	@GeneratedValue
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getCity() {
		return city;
	}

	public void setCity(String city) {
		this.city = city;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@OneToMany(mappedBy = "beerFactory",  cascade = CascadeType.ALL)
	public Set<hibernate.Beer> getBeers() {
		return beers;
	}

	public void setBeers(Set<hibernate.Beer> beers) {
		this.beers = beers;
	}

    public void addBeer(hibernate.Beer beer) {
        beers.add(beer);
        beer.setBeerFactory(this);
    }
 
    public void removeBeer(hibernate.Beer beer) {
    	beers.remove(beer);
    	beer.setBeerFactory(null);
    }

	
}
