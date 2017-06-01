package nextvpu.com.nvpopenblas;

import android.app.Activity;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private static TextView tv;
    private static Activity context;
    private AsyncTask<Integer, Void, Void> task;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        tv = (TextView) findViewById(R.id.sample_text);
        tv.setMovementMethod(new ScrollingMovementMethod());

        final EditText et = (EditText) findViewById(R.id.to);

        findViewById(R.id.start).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv.setText("");
                if (task == null || task.getStatus() != AsyncTask.Status.FINISHED){
                    task = new AsyncTask<Integer, Void, Void>() {
                        @Override
                        protected Void doInBackground(Integer... integers) {
                            stringFromJNI(integers[0]);
                            return null;
                        }

                        @Override
                        protected void onPostExecute(Void aVoid) {
                            super.onPostExecute(aVoid);
                            task = null;
                        }
                    };
                    task.execute(Integer.parseInt(et.getText().toString()));
                }
            }
        });
        context = this;
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native void stringFromJNI(int to);

    public static void callback(final String value) {
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                tv.setText(tv.getText() + value);
            }
        });
    }
}
