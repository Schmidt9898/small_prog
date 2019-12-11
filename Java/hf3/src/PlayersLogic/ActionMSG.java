package PlayersLogic;

public class ActionMSG {
    Msg_type type;
    int x,y,h,w;
    String sender_name;
    String sender_id;
    String msg="";

    public ActionMSG(Msg_type type,int x,int y,int h,int w,String sender_name,
                     String sender_id,
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

    public static ActionMSG move_to(int x,int y,String id,String name)
    {
        return new ActionMSG(Msg_type.MOVE_TO,x,y,0,0
        ,name,id,"");
    }
    public static ActionMSG add(int x,int y,int w,int h,String id,String name)
    {
        return new ActionMSG(Msg_type.MOVE_TO,x,y,h,w
                ,name,id,"");
    }
    public static ActionMSG action(String id,String name,String msg)
    {
        return new ActionMSG(Msg_type.ACTION,0,0,0,0
                ,name,id,msg);
    }
    public static ActionMSG System(String name,String msg)
    {
        return new ActionMSG(Msg_type.SYSTEM,0,0,0,0
                ,name,"-1",msg);
    }
    public static ActionMSG ping(String id,String name)
    {
        return new ActionMSG(Msg_type.PING,0,0,0,0
                ,name,id,"");
    }

    public static ActionMSG fromline(String line)
    {
        String [] lines;

        if(line.length()>0) {
            lines = line.split(",");

            String name ;
            String id ;
            int X,Y,W,H ;
            String MSG;

            switch (lines[0])
            {
                case "MOVE_TO":
                       name = lines[1];
                       id  = lines[2];
                       X   = Integer.parseInt( lines[3]);
                       Y  = Integer.parseInt( lines[4]);
                    return ActionMSG.move_to(X,Y,id,name);


                case "ACTION":
                     name = lines[1];
                    id  = lines[2];
                    MSG   = lines[3];

                    return ActionMSG.action(id,name,MSG);



                case "SYSTEM":
                    name = lines[1];
                    id  = lines[2];
                    MSG   = lines[3];

                    return ActionMSG.System(name,MSG);

                case "PING":
                    name = lines[1];
                    id  = lines[2];
                    return ActionMSG.ping(id,name);
                case "ADD":
                    name = lines[1];
                    id  = lines[2];
                    X   = Integer.parseInt( lines[3]);
                    Y  = Integer.parseInt( lines[4]);
                    H  = Integer.parseInt( lines[5]);
                    W  = Integer.parseInt( lines[6]);
                    return ActionMSG.add(X,Y,W,H,id,name);
                    default:
                        return null;
            }

        }
        return null;
    }




    @Override
    public String toString() {

        String temp="";//=sender_name+","+sender_id+",";
        switch (type)
        {
            case MOVE_TO:
                temp="MOVE_TO,"+sender_name+","+sender_id+","

                        +x+","
                        +y+","
                ;
                break;

            case ACTION:
                temp="ACTION,"+sender_name+","+sender_id+","
                        +msg;


                break;
            case SYSTEM:
                temp="SYSTEM,"+sender_name+","+sender_id+","
                        +msg;

                break;
            case PING:
                temp="PING,"+sender_name+","+sender_id+",";

                break;
            case ADD:
                temp="ACTION,"+sender_name+","+sender_id+","

                        +x+","
                        +y+","
                        +h+","
                        +w+",";
                break;
        }
        return temp;
    }

}
