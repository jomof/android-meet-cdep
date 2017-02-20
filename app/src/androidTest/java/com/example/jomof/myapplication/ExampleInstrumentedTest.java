package com.example.jomof.myapplication;

import android.content.Context;
import android.support.test.InstrumentationRegistry;
import android.support.test.runner.AndroidJUnit4;

import static com.google.common.truth.Truth.assertThat;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.*;


/**
 * Instrumentation test, which will execute on an Android device.
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
@RunWith(AndroidJUnit4.class)
public class ExampleInstrumentedTest {

    public native String checkSqlite();
    public native String checkBoost();
    public native String checkVectorial();

    @Test
    public void useAppContext() throws Exception {
        // Context of the app under test.
        Context appContext = InstrumentationRegistry.getTargetContext();

        assertEquals("com.example.jomof.myapplication", appContext.getPackageName());
    }

    @Test
    public void testCheckSqlite() {
        assertThat(checkSqlite()).isEqualTo("SQLITE_OK");
    }

    @Test
    public void testCheckBoost() {
        assertThat(checkBoost()).isEqualTo("Boost OK");
    }

    @Test
    public void testCheckVectorial() {
        assertThat(checkVectorial()).isEqualTo("Vectorial OK");
    }

    static {
        System.loadLibrary("native-lib");
    }
}
