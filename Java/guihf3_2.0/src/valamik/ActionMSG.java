package valamik;

public class ActionMSG {
    Msg_type type;
    int x=0,y=0,h=0,w=0;
    String sender_name="none";
    int sender_id=0;
    String msg="none";

    public ActionMSG(Msg_type type,int x,int y,int h,int w,String sender_name,
                     int sender_id,
                     String msg
    )
    {
        this.type=type;
        this.x=x;
        this.y=y;
        this.h=h;
        this.w=w;
        this.sender_name=sender_name;
        this.sender_id=sender_id;
        this.msg=msg;


    }

    public static ActionMSG move_to(int x,int y,int id,String name)
    {
        return new ActionMSG(Msg_type.MOVE_TO,x,y,0,0
        ,name,id,"none");
    }
    public static ActionMSG add(int x,int y,int w,int h,int id,String name,String msg)
    {
        return new ActionMSG(Msg_type.ADD,x,y,h,w
                ,name,id,msg);
    }
    public static ActionMSG action(int id,String name,String msg)
    {
        return new ActionMSG(Msg_type.ACTION,0,0,0,0
                ,name,id,msg);
    }
    public static ActionMSG System(String name,String msg)
    {
        return new ActionMSG(Msg_type.SYSTEM,0,0,0,0
                ,name,-1,msg);
    }
    public static ActionMSG ping(int id,String name)
    {
        return new ActionMSG(Msg_type.PING,0,0,0,0
                ,name,id,"none");
    }

    public static ActionMSG System(String msg,int id,String name,int x,int y,int w,int h)
    {
        return new ActionMSG(Msg_type.SYSTEM,x,y,h,w
                ,name,id,msg);
    }


    public static ActionMSG fromline(String line)
    {
        String [] lines;


            lines = line.split(",");
//8 sor
 if(line.length()>=8) {
            String name =lines[1];
            int id =Integer.parseInt(lines[2]);
            int     X = Integer.parseInt( lines[3]),
                    Y = Integer.parseInt( lines[4]),
                    W  = Integer.parseInt( lines[5]),
                    H  = Integer.parseInt( lines[6]);
            String MSG=lines[7];

            switch (lines[0])
            {
                case "MOVE_TO":
                    return ActionMSG.move_to(X,Y,id,name);
                case "ACTION":
                    return ActionMSG.action(id,name,MSG);
                case "SYSTEM":
                    return ActionMSG.System(MSG,id,name,X,Y,W,H);
                case "PING":
                    return ActionMSG.ping(id,name);
                case "ADD":
                    return ActionMSG.add(X,Y,W,H,id,name,MSG);
                    default:
                        return null;
            }

        }
        return null;
    }




    @Override
    public String toString() {

        String temp=
                sender_name+","
                +sender_id+","
                +x+","
                +y+","
                +w+","
                +h+","
                +msg+","
                ;

        switch (type)
        {
            case MOVE_TO:
                temp="MOVE_TO,"+temp;
                break;

            case ACTION:
                temp="ACTION,"+temp;
                break;
            case SYSTEM:
                temp="SYSTEM,"+temp;

                break;
            case PING:
                temp="PING,"+temp;
                break;
            case ADD:
                temp="ADD,"+temp;
                break;
        }
        return temp+"\n";
    }

}
