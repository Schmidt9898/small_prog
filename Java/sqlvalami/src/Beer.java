package hibernate;

import java.util.Date;

import javax.persistence.*;
@Entity
@Table(name = "Beer")
public class Beer {
	
	@Id
	@GeneratedValue
	private int beerId;

	private String name;
	private Date expirationDate;

    @ManyToOne(cascade = CascadeType.ALL)
    @JoinColumn(name = "BEERFACTORY_ID", nullable = true, updatable = false, insertable = true)
    private hibernate.BeerFactory beerFactory;


	public int getBeerId() {
		return beerId;
	}

	public void setBeerId(int beerId) {
		this.beerId = beerId;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Date getExpirationDate() {
		return expirationDate;
	}

    public void setExpirationDate(Date expirationDate) {
		this.expirationDate = expirationDate;
	}

    public hibernate.BeerFactory getBeerFactory() {
        return beerFactory;
    }

    public void setBeerFactory(hibernate.BeerFactory beerFactory) {
        this.beerFactory = beerFactory;
    }




	
	
}
