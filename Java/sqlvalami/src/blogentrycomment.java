import javax.persistence.*;
import java.sql.Date;

@Entity
@Table(name="blogcomment")
public class blogentrycomment {


        int Id;

    @ManyToOne(cascade = CascadeType.ALL)
    @JoinColumn(name = "ID", nullable = true, updatable = false, insertable = true)
        blogentry fkey;

    public blogentry getFkey() {
        return fkey;
    }

    public void setFkey(blogentry fkey) {
        this.fkey = fkey;
    }

    String commenttext;
        java.sql.Date commentdate;



        public blogentrycomment(String comment,Date date)
        {

            this.commenttext=comment;
            this.commentdate=date;
        }


        @Id
        @GeneratedValue
        public int getId() {
            return Id;
        }

        public void setId(int id) {
            Id = id;
        }
    @Column(name="commenttext")
    public String getCommenttext() {
        return commenttext;
    }

    public void setCommenttext(String commenttext) {
        this.commenttext = commenttext;
    }
    @Column(name="commentdate")
    public Date getCommentdate() {
        return commentdate;
    }

    public void setCommentdate(Date commentdate) {
        this.commentdate = commentdate;
    }
}





