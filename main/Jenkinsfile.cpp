pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                script {
                    echo  'build'
                }
            }
        }
        stage('Test') {
            steps {
                script {
                    echo 'test'
                }
            }
        }
        stage('Deploy') {
            steps {
                script {
                    echo 'deploy'
                }
            }
        }
    }

    post {
        failure {
            echo 'pipeline failed'
        }
    }
}
If some error comes in the file, use this
