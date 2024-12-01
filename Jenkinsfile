node {
  stage('SCM') {
    checkout scm
  }
  stage('SonarQube Analysis') {
    def scannerHome = tool 'SonarScanner';
    withSonarQubeEnv('sonarcube') {
      sh "${scannerHome}/bin/sonar-scanner"
    }
  }
}