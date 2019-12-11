


import javax.persistence.*;


@Entity
@Table(name="csokik")
public class categories {

    int categoryId;


    String name;

    String longname;


public categories(String name,String longname)
{
    this.name=name;
    this.longname=longname;
}



    @Id @GeneratedValue
    public int getCategoryId() {
        return categoryId;
    }

    public void setCategoryId(int categoryId) {
        this.categoryId = categoryId;
    }
    @Column(name="neve")
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    @Column(name="description")
    public String getLongname() {
        return longname;
    }

    public void setLongname(String longname) {
        this.longname = longname;
    }
}
