#ifndef CEXTEST_ECDSATEST_H
#define CEXTEST_ECDSATEST_H

#include "ITest.h"

namespace Test
{
	/// <summary>
	/// The ECDSA asymmetric cipher test suite.
	///  <para>Tests public-key, private-key and signature integrity, exception handling, cipher authentication, and a looping stress-test</para>
	/// </summary>
	class ECDSATest final : public ITest
	{
	private:

		static const std::string CLASSNAME;
		static const std::string DESCRIPTION;
		static const std::string SUCCESS;
#if defined (_DEBUG)
		static const size_t TEST_CYCLES = 10;
#else
		static const size_t TEST_CYCLES = 100;
#endif

		std::vector<std::vector<uint8_t>> m_msgexp;
		std::vector<std::vector<uint8_t>> m_pubexp;
		std::vector<std::vector<uint8_t>> m_priexp;
		std::vector<std::vector<uint8_t>> m_rngseed;
		std::vector<std::vector<uint8_t>> m_sigexp;
		TestEventHandler m_progressEvent;

	public:

		/// <summary>
		///  Constructor
		/// </summary>
		ECDSATest();

		/// <summary>
		/// Destructor
		/// </summary>
		~ECDSATest();

		/// <summary>
		/// Get: The test description
		/// </summary>
		const std::string Description() override;

		/// <summary>
		/// Progress return event callback
		/// </summary>
		TestEventHandler &Progress() override;

		/// <summary>
		/// Start the tests
		/// </summary>
		std::string Run() override;

		/// <summary>
		/// Tests the authentication mechanism
		/// </summary>
		void Authentication();

		/// <summary>
		/// Tests the ciphers exception handling functions
		/// </summary>
		void Exception();

		/// <summary>
		/// Compare the shared-secret, cipher-text, public and private key vectors to known answer outputs
		/// </summary>
		void Integrity();

		/// <summary>
		/// Compare the NIST PQ Round 2 known answers to the shared-secret output vectors
		/// </summary>
		void Kat();

		/// <summary>
		/// Tests the for invalid private keys in a looping stress test
		/// </summary>
		void PrivateKey();

		/// <summary>
		/// Tests the for invalid public keys in a looping stress test
		/// </summary>
		void PublicKey();

		/// <summary>
		/// Tests the key serialization function using a looping stress test
		/// </summary>
		void Serialization();

		/// <summary>
		/// Tests the for invalid signatures in a looping stress test
		/// </summary>
		void Signature();

		/// <summary>
		/// Tests the the cipher operations using a looping stress test
		/// </summary>
		void Stress();

	private:

		void Initialize();
		void OnProgress(const std::string &Data);
	};
}

#endif
