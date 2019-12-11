package com.example.madbhazi;

import android.content.Context;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;


// English names by convenction
public class Ujrahasznosito_adapter  extends RecyclerView.Adapter<Ujrahasznosito_adapter.Nezo_tarto>{
    private static final String TAG = "Ujrahasznosito_adapter";

    ArrayList<String> szovegek= new ArrayList<>();
    ArrayList<String> eredmeny= new ArrayList<>();


    Context mContext;

    public Ujrahasznosito_adapter(ArrayList<String> szovegek,Context mContext,ArrayList<String> eredmeny) {
        this.szovegek = szovegek;
        this.mContext = mContext;
        this.eredmeny = eredmeny;
    }

    @NonNull
    @Override
    public Nezo_tarto onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.lista_elem,parent,false);
        Nezo_tarto tarto= new Nezo_tarto(view);


        return tarto;
    }

    @Override
    public void onBindViewHolder(@NonNull Nezo_tarto holder, final int position) {

        Log.d(TAG, "onBindViewHolder: called onbind");
        holder.szoveg.setText(szovegek.get(position));
        holder.parent.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d(TAG, "onClick: clicked");

                Toast.makeText(mContext, eredmeny.get(position), Toast.LENGTH_SHORT).show();
            }
        });

    }

    @Override
    public int getItemCount() {
        return szovegek.size();
    }

    public class Nezo_tarto extends RecyclerView.ViewHolder{
        ImageView kep;
        TextView szoveg;
        RelativeLayout parent;



        public Nezo_tarto(@NonNull View itemView) {
            super(itemView);

            kep=itemView.findViewById(R.id.kepnezo);
            szoveg=itemView.findViewById(R.id.szovegnezo);
            parent=itemView.findViewById(R.id.lista_e);
        }
    }
}
