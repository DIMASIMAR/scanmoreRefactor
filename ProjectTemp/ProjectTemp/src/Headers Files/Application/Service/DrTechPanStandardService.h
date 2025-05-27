class DrTechPanStandardService {
public:
    /**
     * @brief Costruttore
     * @param sensorAdapter Adapter per comunicazione con il sensore DrTech
     * @param deviceAdapter Adapter per comunicazione con il dispositivo NEP
     * @param trajectoryAdapter Adapter per accesso alle traiettorie
     * @param imageProcessingAdapter Adapter per l'elaborazione delle immagini
     * @param fileStorageAdapter Adapter per il salvataggio delle immagini
     * @param eventRegistry Registro per gli eventi del sensore
     */
    DrTechPanStandardService(
    );

    /**
     * @brief Distruttore
     */
    ~DrTechPanStandardService() = default;

    /**
     * @brief Verifica i prerequisiti per l'esecuzione dell'esame
     * @param patientSize Dimensione del paziente
     * @return Stato di validità e messaggio di errore se presenti problemi
     */
    Domain::ValidationResult validatePrerequisites(Domain::PatientSize patientSize);

    /**
     * @brief Prepara il dispositivo e il sensore per l'esame PAN Standard
     * @param examSpec Specifiche dell'esame
     * @return True se la preparazione è completata con successo
     */
    bool prepareExam(const Domain::ExamSpecification& examSpec);

    /**
     * @brief Configura i fattori tecnici dell'esame
     * @param kv Kilovolt per l'esame
     * @param ma Milliampere per l'esame
     * @param enableMRT Flag per abilitare la Modulated Radiation Technology
     * @return True se la configurazione è completata con successo
     */
    bool configureTechnicalFactors(Domain::KiloVolt kv, Domain::MilliAmpere ma, bool enableMRT);

    /**
     * @brief Avvia l'acquisizione dell'esame PAN Standard
     * @return True se l'avvio è completato con successo
     */
    bool startAcquisition();

    /**
     * @brief Interrompe l'acquisizione in corso
     * @return True se l'interruzione è completata con successo
     */
    bool abortAcquisition();

    /**
     * @brief Verifica lo stato dell'acquisizione in corso
     * @return Stato corrente dell'esame
     */
    Domain::ExamState getExamState() const;

    /**
     * @brief Registra un callback per l'aggiornamento dello stato dell'acquisizione
     * @param callback Funzione da chiamare con aggiornamenti di stato
     */
    void registerStateUpdateCallback(std::function<void(Domain::ExamState)> callback);

    /**
     * @brief Registra un callback per il monitoraggio del progresso dell'acquisizione
     * @param callback Funzione da chiamare con aggiornamenti di progresso (0.0-1.0)
     */
    void registerProgressCallback(std::function<void(float)> callback);

    /**
     * @brief Ottiene il percorso dell'immagine acquisita
     * @return Percorso dell'immagine salvata o stringa vuota se non disponibile
     */
    std::string getAcquiredImagePath() const;

    /**
     * @brief Verifica se il sensore DrTech è disponibile
     * @return True se il sensore è connesso e configurato correttamente
     */
    bool isSensorAvailable() const;

    /**
     * @brief Ottiene informazioni diagnostiche sul sensore
     * @return Struttura con informazioni diagnostiche
     */
    Domain::SensorDiagnosticInfo getSensorDiagnostics();

    /**
     * @brief Ottiene i fattori tecnici raccomandati per il paziente
     * @param patientSize Dimensione del paziente
     * @return Fattori tecnici raccomandati (KV, MA)
     */
    Domain::TechnicalFactors getRecommendedFactors(Domain::PatientSize patientSize);

private:
    /**
     * @brief Gestisce gli eventi del sensore
     * @param eventType Tipo di evento
     * @param success Stato di completamento con successo
     * @param errorCode Codice di errore eventuale
     */
    void handleSensorEvent(Domain::SensorEventType eventType, bool success, int errorCode);

    /**
     * @brief Gestisce l'evento di completamento acquisizione
     * @param success Flag che indica se l'acquisizione è avvenuta con successo
     */
    void onAcquisitionCompleted(bool success);

    /**
     * @brief Ricostruisce l'immagine dai frame acquisiti
     * @return True se la ricostruzione è avvenuta con successo
     */
    bool reconstructImage();

    /**
     * @brief Applica i filtri di post-processing all'immagine
     * @param rawImagePath Percorso dell'immagine grezza
     * @return Percorso dell'immagine elaborata
     */
    std::string applyImagePostProcessing(const std::string& rawImagePath);

    /**
     * @brief Gestisce gli errori che si verificano durante l'acquisizione
     * @param errorType Tipo di errore
     * @param errorMessage Messaggio di errore
     * @param errorCode Codice di errore
     */
    void handleError(Domain::ErrorType errorType, const std::string& errorMessage, int errorCode);

    /**
     * @brief Valida la configurazione del sensore e del dispositivo
     * @return True se la configurazione è valida
     */
    bool validateConfiguration();

    /**
     * @brief Prepara la traiettoria per l'esame
     * @return True se la preparazione è completata con successo
     */
    bool prepareTrajectory();

    /**
     * @brief Configura i parametri ottimali per il sensore DrTech
     * @return True se la configurazione è completata con successo
     */
    bool configureSensorParameters();


    private:

        // Stato corrente
        Domain::ExamSpecification _currentExamSpec;
        Domain::ExamState _examState;
        bool _acquisitionInProgress;

        // Callbacks
        std::function<void(Domain::ExamState)> _stateUpdateCallback;
        std::function<void(float)> _progressCallback;

        // Gestione eventi del sensore
        Domain::SensorEvent _acquisitionCompletedEvent;
        Domain::SensorEvent _errorEvent;

        // Risultati dell'acquisizione
        std::string _acquiredImagePath;
        std::vector<Domain::AcquisitionFrame> _acquiredFrames;

        // Metriche di acquisizione
        int _framesAcquired;
        int _framesExpected;
        int _framesLost;
};

} // namespace Service
