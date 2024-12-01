node {
  stage('SCM') {
    checkout scm
  }
  stage('SonarQube Analysis') {
    def scannerHome = tool 'SonarScanner';
    withSonarQubeEnv('sonarcube') {
      sh "${scannerHome}/bin/sonar-scanner -Dsonar.projectKey=test -Dsonar.host.url=http://localhost:9000"
    }
  }
}