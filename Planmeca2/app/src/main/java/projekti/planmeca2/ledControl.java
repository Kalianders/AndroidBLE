package projekti.planmeca2;

/**
 * Created by Antti on 21.6.2016.
 */
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;
import android.app.ProgressDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.os.AsyncTask;
import java.io.IOException;
import java.util.UUID;

public class ledControl {
    Button btnOn, btnOff, btnDis;
    SeekBar brightness;
    String address = null;
    private ProgressDialog progress;
    BluetoothAdapter myBluetooth = null;
    BluetoothSocket btSocket = null;
    private boolean isBtConnected = false;
    static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-0085F9B34FB");

    Intent newint = getIntent();
    address = newint.getStringExtra(DeviceList.EXTRA_ADDRESS);

    setContentView(R.layout.activity_led_control);
    btnOn = (Button)findViewById(R.id.button2);
    btnOff = (Button)findViewById(R.id.button3);
    btnDis = (Button)findViewById(R.id.button4);
    brightness = (SeekBar)findViewById(R.id.seekBar);

}
private class ConnectBT extends AsyncTask<Void, Void, Void> {
    private boolean ConnectSuccess = true;

    @Override
    protected void onPreExecute() {
        progress = ProgressDialog.show(ledControl.this);

    }
    @Override
    protected Void doInBackground(Void.. devices) {
        try
        {
            if (btSocket == null || !isBtConnected)
            {
                myBluetooth = BluetoothAdapter.getDefaultAdapter();//get the mobile bluetooth device
                BluetoothDevice dispositivo = myBluetooth.getRemoteDevice(address);//connects to the device's address and checks if it's available
                btSocket = dispositivo.createInsecureRfcommSocketToServiceRecord(myUUID);//create a RFCOMM (SPP) connection
                BluetoothAdapter.getDefaultAdapter().cancelDiscovery();
                btSocket.connect();//start connection
            }
        }
        catch (IOException e)
        {
            ConnectSuccess = false;//if the try failed, you can check the exception here
        }
        return null;
    }
    @Override
    protected void onPostExecute(Void result) //after the doInBackground, it checks if everything went fine
    {
        super.onPostExecute(result);

        if (!ConnectSuccess)
        {
            msg("Connection Failed. Is it a SPP Bluetooth? Try again.");
            finish();
        }
        else
        {
            msg("Connected.");
            isBtConnected = true;
        }
        progress.dismiss();
    }
}

