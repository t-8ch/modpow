package net.weissschuh.dhbw.match;

import java.math.BigInteger;
import org.openjdk.jmh.annotations.Benchmark;

public class ModPowBenchmark {
	final static private BigInteger base = new BigInteger("1234567890987654321");
	final static private BigInteger exponent = new BigInteger("1234567890987654321");
	final static private BigInteger modulus = new BigInteger("1234567890");

	@Benchmark
	public void test() {
		ModPowBenchmark.base.modPow(ModPowBenchmark.exponent, ModPowBenchmark.modulus);
	}
}
