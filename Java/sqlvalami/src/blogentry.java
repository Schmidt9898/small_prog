import javax.persistence.*;
import java.sql.Date;
import java.util.HashSet;
import java.util.Set;

@Entity
@Table(name="Blog")
public class blogentry {
private int Id;
    private String name;
    private String longname;
    private java.sql.Date date;


    public blogentry(String name,String longname,Date date)
    {

        this.name=name;
        this.longname=longname;
        this.date=date;

    }

    @OneToMany(mappedBy = "fkey",  cascade = CascadeType.ALL)
    public Set<blogentrycomment> getBlogset() {
        return blogset;
    }

    public void setBlogset(Set<blogentrycomment> blogset) {
        this.blogset = blogset;
    }

    Set<blogentrycomment> blogset = new HashSet<blogentrycomment>(0);



    @Id
    @Column(name = "ID")
    @GeneratedValue
    public int getId() {
        return Id;
    }

    public void setId(int id) {
        Id = id;
    }

    @Column(name="name")
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Column(name="longname")
    public String getLongname() {
        return longname;
    }

    public void setLongname(String longname) {
        this.longname = longname;
    }
    @Column(name="datevalami")
    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }
}
