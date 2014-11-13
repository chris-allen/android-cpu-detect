package com.cpudetect.android;

public class CPU {
	static {
		System.loadLibrary("cpu-detect");
	}
	
	public static native String getArchString();
}
