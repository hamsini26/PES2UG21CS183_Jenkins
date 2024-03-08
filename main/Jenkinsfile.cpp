pipeline {
    agent any

    stages {
        stage('Clone repository') {
            steps {
                checkout([
                    scm: [$URL Git],
                    branches: [[branch: 'main']],
                    url: 'https://github.com/hamsini26/PES2UG21CS183_Jenkins'
                ])
            }
        }
        stage('Build') {
            steps {
                build job: 'PES2UG21CS183-1', wait: true
                sh 'sh g++ main.cpp -o output'
            }
        }
        stage('Test') {
            steps {
                sh './output'
            }
        }
        stage('Deploy') {
            steps {
                echo 'deploy'
            }
        }
    }

    post {
        failure {
            echo 'Pipeline failed'
        }
    }
}
