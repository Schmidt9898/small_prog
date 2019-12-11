package com.example.madbhazi;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.Locale;
import android.os.Bundle;

import android.content.Intent;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.View;
import android.widget.Button;


import java.util.ArrayList;


public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";

    private ArrayList<String> lista=new ArrayList<>();
    private ArrayList<String> eredmeny=new ArrayList<>();
    private String lang="en";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Log.d(TAG, "onCreate: ");

        initlista();
        Button gomb = findViewById(R.id.gomb);
        gomb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Log.i(TAG, "--------------------------: "+getResources().getConfiguration().locale.getLanguage() );

                if (getResources().getConfiguration().locale.getLanguage().equals("en")) {
                    lang="hu";


                }
                else {
                    lang="en";

                }
                setLocale(lang);
                }
        });


    }

    public void setLocale(String lang) {
        Locale myLocale = new Locale(lang);
        Resources res = getResources();
        DisplayMetrics dm = res.getDisplayMetrics();
        Configuration conf = res.getConfiguration();
        conf.locale = myLocale;
        Log.i(TAG, "-+++++++++++++++++++++++++++++++++: "+conf.locale.getLanguage() );

       res.updateConfiguration(conf, dm);
        Intent refresh = new Intent(this,MainActivity.class);
        finish();
        startActivity(refresh);
    }





    private void initlista(){
        for(int i=0;i<=100;i++)
        {
            lista.add("3 "+getString(R.string.multiplied) +" "+i+" "+getString(R.string.equal)+" "+"?");
            eredmeny.add(getString(R.string.This)+" "+(i*3));
        }
        initujrahasznosito();
    }


    private void initujrahasznosito(){
        Log.d(TAG, "initujrahasznosito: ");
        RecyclerView recyclerView = findViewById(R.id.recyclerview);
        Ujrahasznosito_adapter adapter=new Ujrahasznosito_adapter(lista,this,eredmeny);
        recyclerView.setAdapter(adapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
    }


}
