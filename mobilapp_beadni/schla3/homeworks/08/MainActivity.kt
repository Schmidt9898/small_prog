package com.example.calculator

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView

class MainActivity : AppCompatActivity() {

    var operated : Boolean =false
    var notsure : Boolean =false


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        findViewById<TextView>(R.id.B).text=""
        findViewById<TextView>(R.id.A).text=""
        findViewById<TextView>(R.id.operator).text=""


        findViewById<Button>(R.id.n0).setOnClickListener {numClick("0")}
        findViewById<Button>(R.id.n1).setOnClickListener {numClick("1")}
        findViewById<Button>(R.id.n2).setOnClickListener {numClick("2")}
        findViewById<Button>(R.id.n3).setOnClickListener {numClick("3")}
        findViewById<Button>(R.id.n4).setOnClickListener {numClick("4")}
        findViewById<Button>(R.id.n5).setOnClickListener {numClick("5")}
        findViewById<Button>(R.id.n6).setOnClickListener {numClick("6")}
        findViewById<Button>(R.id.n7).setOnClickListener {numClick("7")}
        findViewById<Button>(R.id.n8).setOnClickListener {numClick("8")}
        findViewById<Button>(R.id.n9).setOnClickListener {numClick("9")}
        findViewById<Button>(R.id.comma).setOnClickListener {numClick(".")}

        findViewById<Button>(R.id.add).setOnClickListener {opClick("+")}
        findViewById<Button>(R.id.subtract).setOnClickListener {opClick("-")}
        findViewById<Button>(R.id.multiply).setOnClickListener {opClick("*")}
        findViewById<Button>(R.id.divide).setOnClickListener {opClick("/")}

        findViewById<Button>(R.id.del).setOnClickListener {
            if(notsure){

            }else {
                var textview =
                    if (operated) findViewById<TextView>(R.id.B) else findViewById<TextView>(R.id.A)
                textview.text = textview.text.toString().dropLast(1)
                notsure = false
            }
        }

        findViewById<Button>(R.id.clear).setOnClickListener {
            findViewById<TextView>(R.id.B).text=""
            findViewById<TextView>(R.id.A).text=""
            findViewById<TextView>(R.id.operator).text=""
            operated=false
            notsure=false
        }

        findViewById<Button>(R.id.exe).setOnClickListener {
            when(findViewById<TextView>(R.id.operator).text)
            {
                "+" -> findViewById<TextView>(R.id.A).text=sum(findViewById<TextView>(R.id.A).text.toString(),findViewById<TextView>(R.id.B).text.toString())
                "-" -> findViewById<TextView>(R.id.A).text=sub(findViewById<TextView>(R.id.A).text.toString(),findViewById<TextView>(R.id.B).text.toString())
                "/" -> findViewById<TextView>(R.id.A).text=divide(findViewById<TextView>(R.id.A).text.toString(),findViewById<TextView>(R.id.B).text.toString())
                "*" -> findViewById<TextView>(R.id.A).text=multi(findViewById<TextView>(R.id.A).text.toString(),findViewById<TextView>(R.id.B).text.toString())
                "" -> {}
                else -> findViewById<TextView>(R.id.A).text="unknown operator"
            }


            findViewById<TextView>(R.id.B).text=""
            findViewById<TextView>(R.id.operator).text=""
            operated=false
            notsure=true


        }

        findViewById<Button>(R.id.negate).setOnClickListener {
            var textview = if (operated)  findViewById<TextView>(R.id.B) else findViewById<TextView>(R.id.A)
            textview.text=if (textview.text.startsWith('-')) textview.text.drop(1) else "-"+textview.text
            notsure=true
        }








    }


    fun numClick(str : String){
        var textview = if (operated)  findViewById<TextView>(R.id.B) else findViewById<TextView>(R.id.A)
        if(notsure){
            textview.text=""
            notsure=false
        }
        textview.text = textview.text.toString()  + str
    }
    fun opClick(str : String){
        findViewById<TextView>(R.id.operator).text = str
        operated=true
        notsure=true
    }




    fun sum(sa: String, sb: String): String{
        var value = (sa.toDoubleOrNull() ?:0.0 ) + (sb.toDoubleOrNull() ?:0.0)
        return value.toString()
    }
    fun sub(sa: String, sb: String): String{
        var value = (sa.toDoubleOrNull() ?:0.0 ) - (sb.toDoubleOrNull() ?:0.0)
        return value.toString()
    }

    fun multi(sa: String, sb: String): String{
        var value = (sa.toDoubleOrNull() ?:1.0 ) * (sb.toDoubleOrNull() ?:1.0)
        return value.toString()
    }

    fun divide(sa: String, sb: String): String{
        var value = (sa.toDoubleOrNull() ?:0.0 ) / (sb.toDoubleOrNull() ?:1.0)
        return value.toString()
    }
}
