package projekti.planmeca2;

/**
 * Created by Antti on 21.6.2016.
 */

import android.view.View;
import android.widget.Button;
import android.widget.ListView;
import java.util.Set;
import java.util.ArrayList;
import android.widget.Toast;
import android.widget.ArrayAdapter;
import android.widget.AdapterView;
import android.widget.AdapterView.OnClickListener;
import android.widget.TextView;
import android.content.Intent;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;

public class Bluetooth {
    Button btnPaired;
    ListView devicelist;
    btnPaired = (Button)findViewById(R.id.button);
    devicelist = (ListView)findViewById(R.id.listView);
    private BluetoothAdapter myBluetooth = null;
    private Set pairedDevices;

    myBluetooth = BluetoothAdapter.getDefaultAdapter()
    if(myBluetooth == null)
    {
        //Show a mensag. that thedevice has no bluetooth adapter
        Toast.makeText(getApplicationContext(), "Bluetooth Device Not Available", Toast.LENGTH_LONG).show();
        //finish apk
        finish();
    }
    else
    {
        if (myBluetooth.isEnabled())
        { }
        else
        {
            //Ask to the user turn the bluetooth on
            Intent turnBTon = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(turnBTon,1);
        }
    }
    btnPaired.setOnClickListener(new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            pairedDevicesList(); //method that will be called
        }
    }
    private void pairedDevicesList()
    {
        pairedDevices = myBluetooth.getBondedDevices();
        ArrayList list = new ArrayList();

        if (pairedDevices.size()>0)
        {
            for(BluetoothDevice bt : pairedDevices)
            {
                list.add(bt.getName() + "\n" + bt.getAddress()); //Get the device's name and the address
            }
        }
        else
        {
            Toast.makeText(getApplicationContext(), "No Paired Bluetooth Devices Found.", Toast.LENGTH_LONG).show();
        }

        final ArrayAdapter adapter = new ArrayAdapter(this,android.R.layout.simple_list_item_1, list);
        devicelist.setAdapter(adapter);
        devicelist.setOnItemClickListener(myListClickListener); //Method called when the device from the list is clicked

    }

}

